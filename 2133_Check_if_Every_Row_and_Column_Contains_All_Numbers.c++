# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& mat) {
        int n = mat.size();

        // for Row
        for(int i = 0 ; i < n ; i++){
            set<int> rowSet;
            for(int j = 0 ; j < n ; j++){
                rowSet.insert(mat[i][j]);
            }

            if(rowSet.size() != n) return false;
        }

        // for Col
        for(int i = 0 ; i < n ; i++){
            set<int> colSet;
            for(int j = 0 ; j < n ; j++){
                colSet.insert(mat[j][i]);
            }

            if(colSet.size() != n) return false;
        }

        return true;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> matrix = {{1,2,3}, {3,1,2}, {2,3,1}};

    cout<<s1.checkValid(matrix)<<endl;
    
    return 0;
}