#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        vector<char> word(n);
        word[0] = 'a';

        for (int i = 1; i < n; i++) {
            bool found = false;
            char ch = 'a';

            for (int j = 0; j < i; j++) {
                ch = max(ch, word[j]);

                if (lcp[i][j] > 0) {
                    found = true;
                    word[i] = word[j];
                    break;
                }
            }

            if (found) continue;

            if (ch == 'z') return "";
            word[i] = ch + 1;
        }

        // dp[i][j] = LCP of substring starting at i and j
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
            }
        }

        // validate with given lcp matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] != lcp[i][j]) return "";
            }
        }

        return string(word.begin(), word.end());
    }
};

int main(){
    Solution s1;
    vector<vector<int>> lcp = {{4,0,2,0},{0,3,0,1},{2,0,2,0},{0,1,0,1}};

    cout<<s1.findTheString(lcp)<<endl;

    return 0;
}