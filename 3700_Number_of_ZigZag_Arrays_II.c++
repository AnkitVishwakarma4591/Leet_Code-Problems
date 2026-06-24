# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        // Transition matrix
        vector<vector<long long>> T(m, vector<long long>(m, 0));

        for (int j = 0; j < m; j++) {
            for (int i = m - j; i < m; i++) {
                T[i][j] = 1;
            }
        }

        // Compute T^(n-1)
        vector<vector<long long>> powT = matPow(T, n - 1);

        long long total = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                total = (total + powT[i][j]) % MOD;
            }
        }

        return (int)((total * 2) % MOD);
    }

private:
    vector<vector<long long>> matPow(vector<vector<long long>> base, long long exp) {
        int m = base.size();

        vector<vector<long long>> res(m, vector<long long>(m, 0));
        for (int i = 0; i < m; i++) {
            res[i][i] = 1; // Identity matrix
        }

        while (exp > 0) {
            if (exp & 1) {
                res = multiply(res, base);
            }
            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    vector<vector<long long>> multiply(const vector<vector<long long>>& A,
                                       const vector<vector<long long>>& B) {
        int m = A.size();

        vector<vector<long long>> C(m, vector<long long>(m, 0));

        for (int i = 0; i < m; i++) {
            for (int k = 0; k < m; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < m; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }
};

int main(){
    Solution s1;
    int n = 3, l = 4, r = 5;

    cout<<s1.zigZagArrays(n, l, r)<<endl;
    
    return 0;
}