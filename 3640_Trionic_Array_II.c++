# include <bits/stdc++.h>
using namespace std;

// Brute force

// class Solution {
// public:
//     long long maxSumTrionic(vector<int>& nums) {
//         int n = nums.size();
//         long long ans = LLONG_MIN;

//         // choose all subarrays
//         for (int l = 0; l < n; l++) {
//             for (int r = l + 2; r < n; r++) {  // need at least 3 elements
//                 long long sum = 0;
//                 for (int k = l; k <= r; k++) sum += nums[k];

//                 // try all possible peak and valley
//                 for (int i = l + 1; i <= r - 1; i++) {
//                     for (int j = i + 1; j <= r - 1; j++) {

//                         bool ok = true;

//                         // increasing l -> i
//                         for (int k = l; k < i; k++) {
//                             if (nums[k] >= nums[k + 1]) {
//                                 ok = false; break;
//                             }
//                         }

//                         // decreasing i -> j
//                         for (int k = i; k < j; k++) {
//                             if (nums[k] <= nums[k + 1]) {
//                                 ok = false; break;
//                             }
//                         }

//                         // increasing j -> r
//                         for (int k = j; k < r; k++) {
//                             if (nums[k] >= nums[k + 1]) {
//                                 ok = false; break;
//                             }
//                         }

//                         if (ok) {
//                             ans = max(ans, sum);
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    struct Triple {
        int p, q;
        long long sum;
        Triple(int _p, int _q, long long _sum) {
            p = _p;
            q = _q;
            sum = _sum;
        }
    };

    vector<Triple> decompose(vector<int>& nums) {
        int n = nums.size();
        vector<Triple> subarrays;

        int l = 0;
        long long sum = nums[0];

        for (int i = 1; i < n; i++) {
            // break if NOT strictly decreasing
            if (nums[i - 1] <= nums[i]) {
                subarrays.emplace_back(l, i - 1, sum);
                l = i;
                sum = 0;
            }
            sum += nums[i];
        }

        // last segment
        subarrays.emplace_back(l, n - 1, sum);
        return subarrays;
    }

    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();

        // max sum of increasing subarray ending at i
        vector<long long> maxEndingAt(n);
        for (int i = 0; i < n; i++) {
            maxEndingAt[i] = nums[i];
            if (i > 0 && nums[i - 1] < nums[i]) {
                if (maxEndingAt[i - 1] > 0) {
                    maxEndingAt[i] += maxEndingAt[i - 1];
                }
            }
        }

        // max sum of increasing subarray starting at i
        vector<long long> maxStartingAt(n);
        for (int i = n - 1; i >= 0; i--) {
            maxStartingAt[i] = nums[i];
            if (i < n - 1 && nums[i] < nums[i + 1]) {
                if (maxStartingAt[i + 1] > 0) {
                    maxStartingAt[i] += maxStartingAt[i + 1];
                }
            }
        }

        vector<Triple> PQS = decompose(nums);
        long long ans = LLONG_MIN;

        for (auto& t : PQS) {
            int p = t.p;
            int q = t.q;
            long long sum = t.sum;

            // Check valid trionic shape
            if (p > 0 && nums[p - 1] < nums[p] &&
                q < n - 1 && nums[q] < nums[q + 1] &&
                p < q) {

                long long cand =
                    maxEndingAt[p - 1] + sum + maxStartingAt[q + 1];

                ans = max(ans, cand);
            }
        }
        return ans;
    }
};


int main(){
    Solution s1;
    vector<int> nums = {0,-2,-1,-3,0,2,-1};

    cout<<s1.maxSumTrionic(nums)<<endl;
    
    return 0;
}