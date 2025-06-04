    # include <bits/stdc++.h>
    using namespace std;
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;

            if (nums[idx] < 0) {
                ans.push_back(abs(nums[i]));
            } else {
                nums[idx] = -nums[idx];
            }
        }

        return ans;
    }

    int main(){
        vector<int> nums = {4,3,2,7,8,2,3,1};
        for(int val : findDuplicates(nums)){
            cout<<val<<" ";
        }
        return 0;
    }