# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int n){
        if(i >= n){
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }
        int steal = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return t[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        memset(t, -1, sizeof(t));

        return solve(nums, 0, n);
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,3,1};
    cout<<s1.rob(nums)<<endl;
    return 0;
}