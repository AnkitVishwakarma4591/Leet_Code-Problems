# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;
    void solve(string &curr, int n, int open, int close){
        if(curr.size() == 2*n){
            result.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            solve(curr, n, open+1, close);
            curr.pop_back();
        }

        if(close < open){
            curr.push_back(')');
            solve(curr, n, open, close+1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        int open = 0;
        int close = 0;

        solve(curr, n, open, close);

        return result;
    }
};



// class Solution {
// public:
//     vector<string> result;
//     bool isValid(string &curr){
//         int cnt = 0;

//         for(char ch : curr){
//             if(ch == '('){
//                 cnt++;
//             }else{
//                 cnt--;
//                 if(cnt < 0){
//                     return false;
//                 }
//             }
//         }
//         return cnt == 0;
//     }

//     void solve(string &curr, int n){
//         if(curr.size() == 2*n){
//             if(isValid(curr)){
//                 result.push_back(curr);
//             }
//             return;
//         }

//         curr.push_back('(');
//         solve(curr, n);
//         curr.pop_back();

//         curr.push_back(')');
//         solve(curr, n);
//         curr.pop_back();
//     }

//     vector<string> generateParenthesis(int n) {
//         string curr = "";

//         solve(curr, n);

//         return result;
//     }
// };

int main(){
    Solution s1;
    int n = 3;

    for(auto val : s1.generateParenthesis(n)){
        cout<<val<<" ";
    }
    
    return 0;
}