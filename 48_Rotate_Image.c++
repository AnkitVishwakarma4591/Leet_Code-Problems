# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0 ; i < m ; i++){
            for(int j = i ; j < n ; j++){
                if(i != j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        for(int i = 0 ; i < m ; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};


int main(){
    Solution s1;
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    s1.rotate(matrix);

    return 0;
}