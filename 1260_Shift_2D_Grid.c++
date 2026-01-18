# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int row = grid.size();
        int col = grid[0].size();
        int total = row * col;

        k = k % total;

        vector<vector<int>> res(row, vector<int>(col));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int idx = i * col + j;
                int newIdx = (idx + k) % total;

                res[newIdx / col][newIdx % col] = grid[i][j];
            }
        }
        return res;


        // int row = grid.size();
        // int col = grid[0].size();
        // k %= (row * col);

        // while (k--) {
        //     vector<vector<int>> temp(row, vector<int>(col));

        //     temp[0][0] = grid[row-1][col-1];

        //     // first row
        //     for (int j = 1; j < col; j++)
        //         temp[0][j] = grid[0][j-1];

        //     // remaining rows
        //     for (int i = 1; i < row; i++) {
        //         temp[i][0] = grid[i-1][col-1];
        //         for (int j = 1; j < col; j++)
        //             temp[i][j] = grid[i][j-1];
        //     }

        //     grid = temp;
        // }
        // return grid;
    }
};


int main(){
    Solution s1;

    vector<vector<int>> grid = {{3, 8, 1, 9},{19, 7, 2, 5},{4, 6, 11, 10},{12, 0, 21, 13}};
    int k = 4;

    for(auto val : s1.shiftGrid(grid, k)){
        for(auto num : val){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}