# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1000000007;

    int numberOfStableArrays(int zero, int one, int limit) {

        vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));

        for (int i = 1; i <= min(zero, limit); i++) {
            dp[i][0][0] = 1;
        }

        for (int j = 1; j <= min(one, limit); j++) {
            dp[0][j][1] = 1;
        }

        for(int i = 0; i <= zero; i++) {
            for(int j = 0; j <= one; j++) {

                if(i == 0 || j == 0) continue;

                int val0 = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;

                if(i - 1 >= limit) {
                    val0 = (val0 - dp[i - 1 - limit][j][1] + MOD) % MOD;
                }

                dp[i][j][0] = val0;

                int val1 = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;

                if(j - 1 >= limit) {
                    val1 = (val1 - dp[i][j - 1 - limit][0] + MOD) % MOD;
                }

                dp[i][j][1] = val1;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};

int main(){
    Solution s1;
    int zero = 1, one = 1, limit = 2;

    cout<<s1.numberOfStableArrays(zero, one, limit)<<endl;
    
    return 0;
}