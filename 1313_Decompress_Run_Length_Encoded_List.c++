    # include <bits/stdc++.h>
    using namespace std;

    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; ){
            int n = nums[i];
            int p = nums[i+1];
            while(n > 0){
                ans.push_back(p);
                n--;
            }
            i += 2;
        }

        return ans;
    }

    int main(){
        vector<int> nums = {1,2,3,4};
        for(int val : decompressRLElist(nums)){
            cout<<val<<" ";
        }
        return 0;
    }