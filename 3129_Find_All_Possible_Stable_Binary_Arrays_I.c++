# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int limit;
    int MOD = 1000000007;

    int numberOfStableArrays(int zero, int one, int limit) {
        
        this->limit = limit;

        vector<vector<vector<int>>> dp(zero + 1,
            vector<vector<int>>(one + 1, vector<int>(2, 0)));

        dp[0][0][0] = dp[0][0][1] = 1;

        for(int i = 0; i <= zero; i++) {
            for(int j = 0; j <= one; j++) {
                for(int k = 1; k <= limit; k++) {

                    if(i - k >= 0) {
                        dp[i][j][1] = (dp[i][j][1] % MOD + dp[i - k][j][0]) % MOD;
                    }

                    if(j - k >= 0) {
                        dp[i][j][0] = (dp[i][j][0] % MOD + dp[i][j - k][1]) % MOD;
                    }
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};

int main(){
    Solution s1;
    int zero = 3, one = 3, limit = 2;

    cout<<s1.numberOfStableArrays(zero, one, limit)<<endl;
    
    return 0;
}