# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    ll dfs(int r, int c, vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        if (r < 0 || r >= row || c < 0 || c >= col || grid[r][c] == 0) {
            return 0;
        }
        
        ll current_val = grid[r][c];
        grid[r][c] = 0;
        
        ll left = dfs(r, c - 1, grid);
        ll right = dfs(r, c + 1, grid);
        ll top = dfs(r - 1, c, grid);
        ll bottom = dfs(r + 1, c, grid);
        
        return current_val + left + right + top + bottom;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] > 0) {
                    ll total_sum = dfs(i, j, grid);
                    if (total_sum % k == 0) {
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> grid = {{0,2,1,0,0}, {0,5,0,0,5}, {0,0,1,0,0}, {0,1,4,7,0}, {0,2,0,0,8}};
    int k = 5;

    cout<<s1.countIslands(grid, k)<<endl;
    
    return 0;
}