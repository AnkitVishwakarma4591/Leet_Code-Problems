# include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int lSum = 0, rSum = 0, maxSum = 0;

        for(int i = 0 ; i < k ; i++){
            lSum += nums[i];
        }
        maxSum = lSum;

        int idx = n-1;
        for(int i = k-1 ; i >= 0 ; i--){
            lSum -= nums[i];
            rSum += nums[idx];
            maxSum = max(maxSum,(lSum+rSum));
            idx--;
        }
        return maxSum;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,3,4,5,6,1};
    int k = 3;
    cout<<s1.maxScore(nums,k)<<endl;

    return 0;
}