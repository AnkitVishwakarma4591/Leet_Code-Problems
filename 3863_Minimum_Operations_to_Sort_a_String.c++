# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        string t = s;
        sort(t.begin(), t.end());
        if (s == t) return 0;
        
        if (n <= 2) return -1;
        
        char mn = t[0];
        char mx = t[n - 1];
        
        bool min_at_start = (s[0] == mn);
        bool max_at_end = (s[n - 1] == mx);
        
        if (min_at_start || max_at_end) {
            return 1;
        }
        
        bool has_mn_in_prefix = false;
        bool has_mx_in_suffix = false;
        
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == mn) has_mn_in_prefix = true;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == mx) has_mx_in_suffix = true;
        }
        
        if (!has_mn_in_prefix && !has_mx_in_suffix) {
            return 3;
        }
        
        return 2;
    }
};

int main(){
    Solution s1;
    string s = "dog";

    cout<<s1.minOperations(s)<<endl;
    
    return 0;
}