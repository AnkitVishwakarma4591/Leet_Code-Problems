# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n);
        vector<int> rightSum(n);

        leftSum[0] = 0;
        for(int i = 1 ; i < n ; i++){
            leftSum[i] = leftSum[i-1] + nums[i-1];
        }
        rightSum[n-1] = 0;
        for(int i = n-2 ; i >= 0 ; i--){
            rightSum[i] = rightSum[i+1] + nums[i+1];
        }
        vector<int> result(n, 0);
        for(int i = 0 ; i < n ; i++){
            result[i] = abs(leftSum[i] - rightSum[i]);
        }
        return result;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {10,4,8,3};

    for(int val : s1.leftRightDifference(nums)){
        cout<<val<<" ";
    }
    
    return 0;
}