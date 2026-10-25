# include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int r, int c, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }
        
        if (grid[r][c] == 1) {
            return true;
        }
        
        grid[r][c] = 1;
        
        bool left = dfs(r, c - 1, grid);
        bool right = dfs(r, c + 1, grid);
        bool top = dfs(r - 1, c, grid);
        bool bottom = dfs(r + 1, c, grid);
        
        return left && right && top && bottom;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int closedIslandsCount = 0;
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    if (dfs(r, c, grid)) {
                        closedIslandsCount++;
                    }
                }
            }
        }
        
        return closedIslandsCount;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> grid = {{1,1,1,1,1,1,1,0}, {1,0,0,0,0,1,1,0}, {1,0,1,0,1,1,1,0}, {1,0,0,0,0,1,0,1}, {1,1,1,1,1,1,1,0}};

    cout<<s1.closedIsland(grid)<<endl;
    
    return 0;
}