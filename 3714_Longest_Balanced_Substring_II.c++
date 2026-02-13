# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;

    // Case 1: All same characters
    int case1(string &s) {
        int ans = 1;
        int freq = 1;

        for(int i = 1; i < n; i++) {
            if(s[i - 1] == s[i]) {
                freq++;
            } else {
                freq = 1;
            }
            ans = max(ans, freq);
        }

        return ans;
    }

    // Case 2: Only two characters balanced (x and y)
    int case2(string &s, char x, char y) {
        unordered_map<int, int> mp;
        mp[0] = -1;

        int freqX = 0, freqY = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            char ch = s[i];

            if(ch == x) freqX++;
            else if(ch == y) freqY++;
            else {
                mp.clear();
                mp[0] = i;
                freqX = freqY = 0;
                continue;
            }

            int diff = freqX - freqY;

            if(mp.count(diff)) {
                ans = max(ans, i - mp[diff]);
            } else {
                mp[diff] = i;
            }
        }

        return ans;
    }

    // Case 3: All three characters balanced
    int case3(string &s) {
        unordered_map<string, int> mp;
        mp["0$0"] = -1;

        int freqA = 0, freqB = 0, freqC = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            char ch = s[i];

            if(ch == 'a') freqA++;
            else if(ch == 'b') freqB++;
            else freqC++;

            int diffBA = freqB - freqA;
            int diffCA = freqC - freqA;

            string key = to_string(diffBA) + "$" + to_string(diffCA);

            if(mp.count(key)) {
                ans = max(ans, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }

        return ans;
    }

    int longestBalanced(string s) {
        n = s.length();

        int ans = case1(s);

        ans = max(ans, case2(s, 'a', 'b'));
        ans = max(ans, case2(s, 'b', 'c'));
        ans = max(ans, case2(s, 'a', 'c'));

        ans = max(ans, case3(s));

        return ans;
    }
};


int main(){
    Solution s1;
    string s = "abbac";

    cout<<s1.longestBalanced(s)<<endl;

    return 0;
}