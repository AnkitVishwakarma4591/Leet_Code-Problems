# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++) {
            int last = n - 1;

            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == '*') {
                    ans[j][m - 1 - i] = '*';
                    last = j - 1;
                } 
                else if (grid[i][j] == '#') {
                    ans[last][m - 1 - i] = '#';
                    last--;
                }
            }
        }

        return ans;
    }
};


int main(){
    Solution s1;
    vector<vector<char>> grid = {{'#','.','#'}};

    for(auto mat : s1.rotateTheBox(grid)){
        for(auto val : mat){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
}