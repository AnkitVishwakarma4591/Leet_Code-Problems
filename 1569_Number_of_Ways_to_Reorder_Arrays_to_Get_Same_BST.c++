# include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
class Solution {
    using ll = long long;
    static constexpr int MOD = 1e9 + 7;
    static constexpr int MAXN = 1001;
    long long F[MAXN], invF[MAXN];

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

    void precompute() {
        if (F[0] == 1) return;
        F[0] = 1;
        invF[0] = 1;
        for (int i = 1; i < MAXN; i++) {
            F[i] = (F[i - 1] * i) % MOD;
        }
        invF[MAXN - 1] = modInverse(F[MAXN - 1]);
        for (int i = MAXN - 2; i >= 1; i--) {
            invF[i] = (invF[i + 1] * (i + 1)) % MOD;
        }
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        return F[n] * invF[r] % MOD * invF[n - r] % MOD;
    }

    long long solve(const vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long leftWays = solve(left);
        long long rightWays = solve(right);

        long long ways = nCr(n - 1, left.size());
        ways = (ways * leftWays) % MOD;
        ways = (ways * rightWays) % MOD;
        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        precompute();
        return (solve(nums) - 1 + MOD) % MOD;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {2,1,3};

    cout<<s1.numOfWays(nums)<<endl;

    return 0;
}