# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        int open = 0;
        int close = 0;

        int result = 0;

        // Left to right
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                open++;
            }else{
                close++;
            }

            if(open == close){
                result = max(result, open+close);
            }else if(close > open){
                open = close = 0;
            }
        }

        // right ot left
        open  = 0;
        close = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == '('){
                open++;
            }else{
                close++;
            }

            if(open == close){
                result = max(result, open+close);
            }else if(open > close){
                open = close = 0;
            }
        }

        return result;
    }
};

int main(){
    Solution s1;
    string s = ")()())";

    cout<<s1.longestValidParentheses(s)<<endl;
    
    return 0;
}