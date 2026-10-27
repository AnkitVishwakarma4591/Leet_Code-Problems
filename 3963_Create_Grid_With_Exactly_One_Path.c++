# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#')); 
        
        for (int j = 0; j < n; ++j) {
            grid[0][j] = '.';
        }
        
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};

int main(){
    Solution s1;
    int m = 2, n = 3;

    for(auto val  : s1.createGrid(m, n)){
        cout<<val<<" ";
    }
    
    return 0;
}