# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotated(vector<vector<int>>& mat){
        int m = mat.size();
        int n = mat[0].size();

        // Transpose
        for(int i = 0 ; i < m ; i++){
            for(int j = i ; j < n ; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Reverse
        for(int i = 0 ; i < m ; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int m = mat.size();
        int n = mat[0].size();

        for(int c = 1 ; c <= 4 ; c++){
            bool isEqual = true;
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(mat[i][j] != target[i][j]){
                        isEqual = false;
                        break; 
                    }
                }
            }
            if(!isEqual){
                rotated(mat);
            }
            if(isEqual) return true;
        }
        return false;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> mat = {{0,1},{1,0}};
    vector<vector<int>> target = {{1,0},{0,1}};

    cout<<s1.findRotation(mat, target)<<endl;

    return 0;
}