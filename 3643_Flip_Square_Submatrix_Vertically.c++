# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int startRow = x;
        int endRow = x+k-1;

        int startCol = y;
        int endCol = y+k-1;

        for(int i = startRow ; i <= endRow ; i++){
            for(int j = startCol ; j <= endCol ; j++){
                swap(grid[i][j], grid[endRow][j]);
            }
            endRow--;
        }
        return grid;
    }
};

int main(){
    Solution s1;

    vector<vector<int>> grid = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int x = 1, y = 0, k = 3;

    for(auto mat : s1.reverseSubmatrix(grid, x, y, k)){
        for(int val : mat){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}