# include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;  

        int cnt = 0, needCount = need.size();
        int l = 0;
        int minLen = INT_MAX, st = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (need.count(c) && window[c] == need[c])
                cnt++;

            while (cnt == needCount) {
                // update answer
                if ((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    st = l;
                }

                // shrink
                window[s[l]]--;
                if (need.count(s[l]) && window[s[l]] < need[s[l]])
                    cnt--;
                l++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(st, minLen);
    }
};


int main(){
    Solution s1;
    string s = "ADOBECODEBANC", t = "ABC";

    for(auto val : s1.minWindow(s, t)){
        cout<<val;
    }

    return 0;
}