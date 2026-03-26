# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotation(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> temp(n, vector<int>(m));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                temp[j][m - i - 1] = grid[i][j];
            }
        }

        return temp;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long totalSum = 0;
        for(auto &row : grid) {
            for(auto &val : row) {
                totalSum += val;
            }
        }

        for(int k = 0; k < 4; k++) {
            unordered_set<long long> exist;
            exist.insert(0LL);

            long long topSum = 0;

            m = grid.size();
            n = grid[0].size();

            if(m < 2) {
                grid = rotation(grid);
                continue;
            }

            if(n == 1) {
                for(int i = 0; i < m - 1; i++) {
                    topSum += grid[i][0];
                    long long diff = topSum * 2 - totalSum;

                    if(diff == 0 || diff == grid[0][0] || diff == grid[i][0])
                        return true;
                }

                grid = rotation(grid);
                continue;
            }

            for(int i = 0; i < m - 1; i++) {
                for(int j = 0; j < n; j++) {
                    exist.insert((long long)grid[i][j]);
                    topSum += grid[i][j];
                }

                long long diff = topSum * 2 - totalSum;

                if(i == 0) {
                    if(diff == 0 || diff == grid[0][0] || diff == grid[0][n - 1])
                        return true;
                    continue;
                }

                if(exist.count(diff)) return true;
            }

            grid = rotation(grid);
        }

        return false;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> grid = {{1,4},{2,3}};

    cout<<s1.canPartitionGrid(grid)<<endl;
    
    return 0;
}