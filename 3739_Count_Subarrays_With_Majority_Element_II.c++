# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int len = 2 * n + 2;
        
        vector<long long> countAtSum(len, 0);
        vector<long long> cumulativeCount(len, 0);
        
        int idx = n + 1;
        countAtSum[idx] = 1;
        
        // Initialize prefix sums up to idx
        for (int i = idx; i < len; i++) {
            cumulativeCount[i] = 1;
        }
        
        long long ans = 0;
        
        for (int num : nums) {
            if (num == target) {
                idx++;
            } else {
                idx--;
            }
            
            ans += cumulativeCount[idx - 1];
            
            countAtSum[idx]++;
            
            // Maintaining the running prefix sum array correctly
            cumulativeCount[idx] = cumulativeCount[idx - 1] + countAtSum[idx];
        }
        
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,2,3};
    int target = 2;

    cout<<s1.countMajoritySubarrays(nums, target)<<endl;
    
    return 0;
}