# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j] stores all possible XOR values to reach cell (i, j)
        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));
        
        // Base case: starting cell (0, 0)
        dp[0][0].insert(grid[0][0]);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // From top cell (i-1, j)
                if (i > 0) {
                    for (int val : dp[i - 1][j]) {
                        dp[i][j].insert(val ^ grid[i][j]);
                    }
                }
                // From left cell (i, j-1)
                if (j > 0) {
                    for (int val : dp[i][j - 1]) {
                        dp[i][j].insert(val ^ grid[i][j]);
                    }
                }
            }
        }
        
        // Find the minimum XOR value at the bottom-right cell (m - 1, n - 1)
        int min_xor = 1024;
        for (int val : dp[m - 1][n - 1]) {
            min_xor = min(min_xor, val);
        }
        
        return min_xor;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> grid = {{1,2}, {3,4}};

    cout<<s1.minCost(grid)<<endl;

    return 0;
}