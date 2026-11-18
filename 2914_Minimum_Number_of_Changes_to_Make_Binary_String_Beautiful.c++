# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        // Check adjacent pairs (i, i+1) with a step of 2
        for (int i = 0; i < s.size(); i += 2) {
            if (s[i] != s[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
};



int main(){
    Solution s1;
    string s = "1001";

    cout<<s1.minChanges(s)<<endl;
    
    return 0;
}