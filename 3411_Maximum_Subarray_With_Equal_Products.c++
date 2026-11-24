# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    ll gcd(int a, int b){
        if(b == 0) return a;

        return gcd(b, a%b);
    }

    ll lcm(int a, int b){
        ll rem = gcd(a, b);

        return (a*b)/rem;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            ll prod = 1;
            ll g = 0;
            ll lc = 1;

            for (int j = i; j < n; ++j) {
                ll x = nums[j];
                g = (g == 0) ? x : gcd(g, x);
                lc = lcm(lc, x);

                if (prod > LLONG_MAX / x) {
                    break;
                }
                prod *= x;

                if (prod == lc * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution s1;

    vector<int> nums = {1, 2, 1, 2, 1, 1, 1};

    cout<<s1.maxLength(nums)<<endl;

    return 0;
}