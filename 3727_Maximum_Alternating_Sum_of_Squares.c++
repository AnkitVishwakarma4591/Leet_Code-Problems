# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            nums[i] = nums[i] * nums[i];
        }

        nth_element(nums.begin(), nums.begin() + n/2, nums.end());

        long long largeHalf = accumulate(nums.begin()+n/2, nums.end(), 0LL);
        long long smallHalf = accumulate(nums.begin(), nums.begin()+n/2, 0LL);

        return largeHalf - smallHalf;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,-1,2,-2,3,-3};

    cout<<s1.maxAlternatingSum(nums)<<endl;
    
    return 0;
}