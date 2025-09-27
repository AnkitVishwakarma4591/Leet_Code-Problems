# include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int l = 0, maxFreq = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);

            // if replacements needed > k, shrink window
            while ((r - l + 1) - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};

int main(){
    Solution s1;
    string s = "ABAB";
    int k = 2;

    cout<<s1.characterReplacement(s,k)<<endl;

    return 0;
}