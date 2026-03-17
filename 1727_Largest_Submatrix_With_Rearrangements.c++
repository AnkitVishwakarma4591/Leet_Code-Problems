# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 1 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == 1){
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }
        
        int ans = 0;
        for(auto row : matrix){
            sort(row.begin(), row.end());

            for(int j = 1 ; j <= n ; j++){
                int currAns = j * row[n-j];
                ans = max(ans, currAns);
            }
        }
        return ans;
    }
};


int main(){
    Solution s1;
    vector<vector<int>> matrix = {{0,0,1},{1,1,1},{1,0,1}};

    cout<<s1.largestSubmatrix(matrix)<<endl;
    
    return 0;
}