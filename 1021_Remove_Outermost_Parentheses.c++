# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (depth > 0) {
                    result += ch;
                }
                depth++;
            } else if (ch == ')') {
                depth--;
                if (depth > 0) {
                    result += ch;
                }
            }
        }

        return result;
    }
};

int main(){
    Solution s1;
    string s = "(()())(())";

    cout<<s1.removeOuterParentheses(s)<<endl;
    
    return 0;
}