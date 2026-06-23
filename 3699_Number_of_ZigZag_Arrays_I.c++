#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;
    using ll = long long;

    int zigZagArrays(int n, int l, int r) {
        int M = r - l + 1;

        // Length 1 ke liye har value valid hai
        if (n == 1) {
            return M;
        }

        // Heap allocation + zero initialization
        vector<vector<array<ll, 2>>> t(
            n + 1,
            vector<array<ll, 2>>(M + 1, {0, 0})
        );

        // Base Case
        for (int prevVal = 1; prevVal <= M; prevVal++) {
            t[n][prevVal][0] = 1;
            t[n][prevVal][1] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {

            vector<ll> prefDir0(M + 1, 0);
            vector<ll> prefDir1(M + 1, 0);

            for (int prevVal = 1; prevVal <= M; prevVal++) {
                prefDir0[prevVal] =
                    (prefDir0[prevVal - 1] + t[i + 1][prevVal][0]) % MOD;

                prefDir1[prevVal] =
                    (prefDir1[prevVal - 1] + t[i + 1][prevVal][1]) % MOD;
            }

            for (int prevVal = 1; prevVal <= M; prevVal++) {

                // Next value > prevVal
                t[i][prevVal][1] =
                    (prefDir0[M] - prefDir0[prevVal] + MOD) % MOD;

                // Next value < prevVal
                t[i][prevVal][0] =
                    prefDir1[prevVal - 1];
            }
        }

        ll result = 0;

        for (int startVal = 1; startVal <= M; startVal++) {
            // a < b > c < d ...
            result = (result + t[1][startVal][1]) % MOD;

            // a > b < c > d ...
            result = (result + t[1][startVal][0]) % MOD;
        }

        return (int)result;
    }
};

int main() {
    Solution s;

    int n = 3, l = 4, r = 5;

    cout << s.zigZagArrays(n, l, r) << endl;

    return 0;
}