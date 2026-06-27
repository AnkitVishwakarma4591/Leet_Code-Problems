# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // Frequency map for all elements
        unordered_map<long long, int> hmap;
        int ones = 0;
        
        for (int num : nums) {
            hmap[num]++;
            if (num == 1) {
                ones++;
            }
        }

        // 1^k is always 1, so any odd-length subsequence of 1s is valid
        // If count is even, best odd length we can pick is ones - 1
        int ans = (ones % 2 == 0) ? ones - 1 : ones;

        // 1s are already handled — remove to avoid reprocessing in chain logic
        hmap.erase(1);

        for (auto const& entry : hmap) {
            long long num = entry.first;
            int freq = entry.second;
            int count = 0;
            long long curr = num;

            // Follow the squaring chain: num -> num^2 -> num^4 -> ...
            while (hmap.count(curr)) {
                if (hmap[curr] >= 2) {
                    count += 2; // Can take a pair at this level
                } else {
                    count++;    // Only one occurrence — can end the chain here
                    break;      // Cannot continue: need pairs to keep squaring
                }
                
                // Overflow check before squaring to avoid undefined behavior
                if (curr > 100000) { 
                    break; 
                }
                curr = curr * curr;
            }

            // Subsequence must have odd length to satisfy the zigzag/power condition
            if (count % 2 == 0) {
                count--;
            }
            ans = max(ans, count);
        }

        // Ensuring we return at least 1 since any single element subset is valid
        return max(ans, 1);
    }
};

int main(){
    Solution s1;
    vector<int> nums = {5,4,1,2,2};

    cout<<s1.maximumLength(nums)<<endl;

    return 0;
}