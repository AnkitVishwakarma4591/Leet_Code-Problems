# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] != i){
                k = (k & nums[i]);
            }
        }
        return k == -1 ? 0 : k;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {0,3,2,1};

    cout<<s1.sortPermutation(nums)<<endl;
    
    return 0;
}