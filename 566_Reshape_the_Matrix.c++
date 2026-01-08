# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size(), col = mat[0].size();
        if(row * col != r * c) return mat;
        
        vector<int> temp;

        for(auto val : mat){
            for(int num : val){
                temp.push_back(num);
            }
        }

        vector<vector<int>> ans(r, vector<int>(c));
        int idx = 0;
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                ans[i][j] = temp[idx];
                idx++;
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;

    vector<vector<int>> mat = {{1,2},{3,4}};

    int r = 1, c = 4;

    for(auto val : s1.matrixReshape(mat,r,c)){
        for(int num : val){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}