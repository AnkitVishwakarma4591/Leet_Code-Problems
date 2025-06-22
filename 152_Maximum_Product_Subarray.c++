# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1 , suff = 1;
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;

            pre = pre * nums[i];
            suff = suff * nums[n-i-1];

            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {2,3,-2,4};

    cout<<s1.maxProduct(nums)<<endl;

    return 0;
}