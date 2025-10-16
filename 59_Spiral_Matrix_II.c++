# include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int idx = 1;
        int srow = 0 , scol = 0, erow = n-1, ecol = n-1;
        vector<vector<int>> ans(n, vector<int>(n, 0));

        while(srow <= erow && scol <= ecol){
            //top
            for(int i = scol ; i <= ecol ; i++){
                ans[srow][i] = idx++;
            }
            //right
            for(int i = srow + 1 ; i <= erow ; i++){
                ans[i][ecol] = idx++;
            }
            //bottom
            for(int i = ecol-1 ; i >= scol ; i--){
                if(srow == erow) break;
                ans[erow][i] = idx++;
            }
            //left
            for(int i = erow-1 ; i > srow ; i--){
                if(scol == ecol) break;
                ans[i][scol] = idx++;
            }
            srow++; erow--; scol++; ecol--;
        }
        return ans;
    }
};

int main(){
    Solution s1;
    int n = 3;

    for(auto mat : s1.generateMatrix(n)){
        for(auto val : mat){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
}