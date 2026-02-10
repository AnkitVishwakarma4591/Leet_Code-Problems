# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int idx = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != 0){
                ans[idx] = nums[i];
                idx++;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                ans[idx] = nums[i];
                idx++;
            }
        }
        nums = ans; 
    }
};

int main(){
    Solution s1;
    vector<int>  nums = {0,1,0,3,12};

    s1.moveZeroes(nums);
    
    return 0;
}