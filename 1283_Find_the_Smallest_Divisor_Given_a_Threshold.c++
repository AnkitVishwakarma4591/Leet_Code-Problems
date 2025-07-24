# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int total = 0;

            for (int num : nums) {
                total += ceil((double)num / mid);
            }

            if (total > threshold) {
                left = mid + 1;
            } else {
                result = mid; // possible answer
                right = mid - 1;
            }
        }
        return result;
    }
};

int main(){
    vector<int> arr = {1,2,5,9};
    int threshold = 6;

    Solution s1;
    cout<<s1.smallestDivisor(arr,threshold)<<endl;
}