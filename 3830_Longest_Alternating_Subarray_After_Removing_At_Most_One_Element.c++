# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAlternating(vector<int>& v) {
        int n = v.size(), m = 1;
        if (n < 2) return n;
        vector<int> a(n, 1), b(n, 1), c(n, 1), d(n, 1);
        for (int i = 1; i < n; ++i) {
            if (v[i] > v[i - 1]) a[i] = b[i - 1] + 1;
            if (v[i] < v[i - 1]) b[i] = a[i - 1] + 1;
            m = max(m, max(a[i], b[i]));
        }
        for (int i = n - 2; i >= 0; --i) {
            if (v[i] < v[i + 1]) c[i] = d[i + 1] + 1;
            if (v[i] > v[i + 1]) d[i] = c[i + 1] + 1;
        }
        for (int i = 1; i < n - 1; ++i) {
            if (v[i - 1] < v[i + 1]) m = max(m, b[i - 1] + d[i + 1]);
            if (v[i - 1] > v[i + 1]) m = max(m, a[i - 1] + c[i + 1]);
        }
        return m;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {2,1,3,2};

    cout<<s1.longestAlternating(nums)<<endl;
    
    return 0;
}