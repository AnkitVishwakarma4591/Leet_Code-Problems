# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<bool> row(m, false);

        for(int i = 0; i < m; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                sum += mat[i][j];
            }

            if(sum == 1) {
                row[i] = true;
            }
        }

        int count = 0;

        for(int j = 0; j < n; j++) {
            int sum = 0;
            int idx = 0;

            for(int i = 0; i < m; i++) {
                if(mat[i][j] == 1) {
                    sum += 1;
                    idx = i;
                }
            }

            if(sum == 1 && row[idx]) {
                count++;
            }
        }

        return count;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> mat = {{1, 0, 0},{0, 0, 1},{1, 0, 0}};

    cout<<s1.numSpecial(mat)<<endl;
    
    return 0;
}