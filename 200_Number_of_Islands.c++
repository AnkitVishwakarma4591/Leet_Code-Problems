# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;
    int n;
    void dfs(vector<vector<char>> &grid, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1'){
            return;
        }

        if(grid[i][j] == -1){
            return;
        }

        grid[i][j] = '$';

        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int island = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    island++;
                }
            }
        }

        return island;
    }
};

int main(){
    Solution s1;
    vector<vector<char>> grid = {{'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'}
                            };
    cout<<s1.numIslands(grid)<<endl;
    return 0;
}