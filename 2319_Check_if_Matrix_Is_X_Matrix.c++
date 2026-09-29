# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n =  grid.size();
        int m =  grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == j || i+j == n-1){
                    if(grid[i][j] == 0) return false;
                }else if(grid[i][j] != 0) return false;
            }
        }

        return true;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> grid = {{2,0,0,1}, {0,3,1,0}, {0,5,2,0}, {4,0,0,2}};

    cout<<s1.checkXMatrix(grid)<<endl;
    
    return 0;
}