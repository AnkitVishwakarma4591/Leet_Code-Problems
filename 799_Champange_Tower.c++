# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double result[101][101] = {0.0};
        result[0][0] = poured;
        for(int i = 0 ; i < 100 ; i++){
            for(int j = 0 ; j <= i ; j++){
                if(result[i][j] >= 1){
                    result[i+1][j] += (result[i][j]-1)/2.0;
                    result[i+1][j+1] += (result[i][j] -1)/2.0;
                    result[i][j] = 1;
                }
            }
        }
        return result[query_row][query_glass];
    }
};

int main(){
    Solution s1;
    int poured = 1, query_row = 1, query_glass = 1;

    cout<<s1.champagneTower(poured, query_row, query_glass)<<endl;
    
    return 0;
}