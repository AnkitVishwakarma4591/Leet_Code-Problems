# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int target = totalSum - x;

        // If target is 0, we need to remove all elements to sum to x
        if (target == 0) return nums.size();
        // If totalSum < x, it's impossible to reach x
        if (target < 0) return -1;

        int left = 0;
        int currentSum = 0;
        int maxLen = -1;

        for (int right = 0; right < nums.size(); ++right) {
            currentSum += nums[right];

            // Shrink window if the sum exceeds target
            while (left <= right && currentSum > target) {
                currentSum -= nums[left];
                left++;
            }

            // Update max length if target match is found
            if (currentSum == target) {
                maxLen = std::max(maxLen, right - left + 1);
            }
        }

        return maxLen == -1 ? -1 : nums.size() - maxLen;
    }
};

int main(){
    Solution s1;

    vector<int> nums = {1,1,4,2,3};
    int x = 5;

    cout<<s1.minOperations(nums, x)<<endl;

    return 0;
}