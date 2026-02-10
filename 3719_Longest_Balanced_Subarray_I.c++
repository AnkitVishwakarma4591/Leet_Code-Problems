# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int L = 0; L < n; L++) {
            unordered_set<int> evenSet, oddSet;

            for (int R = L; R < n; R++) {
                if (nums[R] % 2 == 0)
                    evenSet.insert(nums[R]);
                else
                    oddSet.insert(nums[R]);

                if (evenSet.size() == oddSet.size()) {
                    ans = max(ans, R - L + 1);
                }
            }
        }
        return ans;
    }
};


int main(){
    Solution s1;
    vector<int> nums = {3,2,2,5,4};

    cout<<s1.longestBalanced(nums)<<endl;
    
    return 0;
}