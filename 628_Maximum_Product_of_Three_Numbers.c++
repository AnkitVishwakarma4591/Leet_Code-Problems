# include <bits/stdc++.h>
using namespace std;

// class Solution:
//     def maximumProduct(self, nums: List[int]) -> int:
//         max1, max2, max3 = float('-inf'),float('-inf'),float('-inf')
//         min1, min2 = float('inf'),float('inf')

//         for num in nums:
//             if num > max1:
//                 max3 = max2
//                 max2 = max1
//                 max1 = num
//             elif num > max2:
//                 max3 = max2
//                 max2 = num
//             elif num > max3:
//                 max3 = num

//             if num < min1:
//                 min2 = min1
//                 min1 = num
//             elif num < min2:
//                 min2 = num
        
//         return max(max1*max2*max3, min1*min2*max1)
// Python code

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int x : nums) {
            // Track 3 largest
            if (x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max3 = max2;
                max2 = x;
            } else if (x > max3) {
                max3 = x;
            }

            // Track 2 smallest
            if (x < min1) {
                min2 = min1;
                min1 = x;
            } else if (x < min2) {
                min2 = x;
            }
        }

        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,3};

    cout<<s1.maximumProduct(nums)<<endl;

    return 0;
}