# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int maxLen = 1;
        int incLen = 1;
        int decLen = 1;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                incLen++;
                decLen = 1;
            } else if (nums[i] < nums[i - 1]) {
                decLen++;
                incLen = 1;
            } else {
                incLen = 1;
                decLen = 1;
            }
            maxLen = max({maxLen, incLen, decLen});
        }
        
        return maxLen;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,4,3,3,2};

    cout<<s1.longestMonotonicSubarray(nums)<<endl;

    return 0;
}