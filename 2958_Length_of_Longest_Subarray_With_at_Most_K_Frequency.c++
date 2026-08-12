# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int left = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            m[nums[right]]++;

            while (m[nums[right]] > k) {
                m[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};


// class Solution {
// public:
//     int maxSubarrayLength(vector<int>& nums, int k) {
//         int n = nums.size();

//         unordered_map<int, int> m;

//         int left = 0, right = 0;
//         int arr_len = 0;

//         while (right < n) {

//             if (m.find(nums[right]) == m.end()) {
//                 m[nums[right]] = 1;
//                 right++;
//             }
//             else if (m[nums[right]] < k) {
//                 m[nums[right]]++;
//                 right++;
//             }
//             else {
//                 m[nums[left]]--;
//                 left++;
//             }

//             arr_len = max(arr_len, right - left);
//         }

//         return arr_len;
//     }
// };


int main(){
    Solution s1;
    vector<int> nums = {1,2,3,1,2,3,1,2};
    int k = 2;

    cout<<s1.maxSubarrayLength(nums, k)<<endl;
    
    return 0;
}