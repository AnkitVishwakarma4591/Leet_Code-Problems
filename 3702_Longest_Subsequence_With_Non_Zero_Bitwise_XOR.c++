# include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int val : nums){
            ans ^= val;
        }

        if(ans != 0) return nums.size();

        for(int i = 0 ; i < n ; i++){
            if(ans ^ nums[i] != 0){
                return n-1;
            }
        }

        return 0;

    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,3};

    cout<<s1.longestSubsequence(nums)<<endl;
    
    return 0;
}