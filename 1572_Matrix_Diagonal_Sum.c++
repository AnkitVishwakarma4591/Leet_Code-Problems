    # include <bits/stdc++.h>
    using namespace std;
    
    int diagonalSum(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int sum = 0;

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(i == j || j == col - i-1){
                    sum += mat[i][j];
                }
            }
        }

        return sum;
        
    }

    int main(){
        vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
        cout<<diagonalSum(matrix)<<endl;
        return 0;
    }