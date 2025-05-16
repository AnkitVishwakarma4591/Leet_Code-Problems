# include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<int>> transpose(col, vector<int>(row, 0));

    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            transpose[j][i] = matrix[i][j];
        }
    }
    return transpose;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    for(auto row : transpose(matrix)){
        for(auto val : row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}