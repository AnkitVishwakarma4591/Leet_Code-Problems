# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int d1[256]{};
        int d2[256]{};
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char a = s[i], b = t[i];
            if (d1[a] != d2[b]) {
                return false;
            }
            d1[a] = d2[b] = i + 1;
        }
        return true;
    }
};

int main(){
    Solution s1;
    string s = "egg", t = "add";
    cout<<s1.isIsomorphic(s,t)<<endl;

    return 0;
}