# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Dp max to min
        vector<vector<long long>> dpMax(m, vector<long long>(n));
        vector<vector<long long>> dpMin(m, vector<long long>(n));

        dpMax[0][0] = grid[0][0];
        dpMin[0][0] = grid[0][0];

        // first row
        for(int i = 1 ; i < n ; i++){
            dpMax[0][i] = dpMax[0][i-1]*grid[0][i];
            dpMin[0][i] = dpMin[0][i-1]*grid[0][i];
        }

        // first col
        for(int i = 1 ; i < m ; i++){
            dpMax[i][0] = dpMax[i-1][0]*grid[i][0];
            dpMin[i][0] = dpMin[i-1][0]*grid[i][0];
        }

        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                int val = grid[i][j];
                long topMax = dpMax[i-1][j]*val;
                long topMin = dpMin[i-1][j]*val;
                long leftMax = dpMax[i][j-1]*val;
                long leftMin = dpMin[i][j-1]*val;

                dpMax[i][j] = max(max(topMax, topMin), max(leftMax, leftMin));
                dpMin[i][j] = min(min(topMax, topMin), min(leftMax, leftMin));
            }
        }
        long ans = dpMax[m-1][n-1];
        return ans < 0 ? -1 : (int)(ans%mod);
    }
};

int main(){
    Solution s1;

    vector<vector<int>> grid = {{1,-2,1},{1,-2,1},{3,-4,1}};

    cout<<s1.maxProductPath(grid)<<endl;
    
    return 0;
}