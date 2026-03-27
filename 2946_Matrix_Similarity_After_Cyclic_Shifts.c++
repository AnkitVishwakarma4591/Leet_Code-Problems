# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k = k % n;
        vector<vector<int>> temp = mat;

        for(int i = 0 ; i < m ; i++){
            if(i % 2 == 0){
                reverse(mat[i].begin(), mat[i].begin()+k);  // first k
                reverse(mat[i].begin()+k, mat[i].end());    // remaining
                reverse(mat[i].begin(), mat[i].end());      // full
            }else{
                reverse(mat[i].begin(), mat[i].end());   // full
                reverse(mat[i].begin(), mat[i].begin()+k);   // first k
                reverse(mat[i].begin()+k, mat[i].end());   // remaining
            }
        }
        return temp == mat;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 4;

    cout<<s1.areSimilar(mat, k)<<endl;
    
    return 0;
}