# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int val : nums) totalSum += val;

        int leftSum = 0;
        for(int i = 0 ; i < n ; i++){
            if(leftSum == (totalSum - leftSum - nums[i])) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,7,3,6,5,6};

    cout<<s1.pivotIndex(nums)<<endl;
    
    return 0;
}