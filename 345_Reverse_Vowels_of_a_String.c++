#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowels(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string reverseVowels(string s) {
        int st = 0, end = s.size() - 1;

        while (st < end) {
            if (!isVowels(s[st])) {
                st++;
                continue;
            }
            if (!isVowels(s[end])) {
                end--;
                continue;
            }
            swap(s[st], s[end]);
            st++;
            end--;
        }

        return s;
    }
};

int main(){
    Solution s1;
    string s = "IceCreAm";

    string ans = s1.reverseVowels(s);
    for(auto val : ans){
        cout<<val;
    }
    
    return 0;
}
