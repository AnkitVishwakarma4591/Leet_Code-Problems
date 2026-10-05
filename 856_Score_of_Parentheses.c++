# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int  n = s.size();

        int score = 0;
        int depth = 0;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                depth++;
            }else{ // )
                depth--;
                if(s[i-1] == '('){
                    score += (1 << depth);
                }
            }
        }
        return score;
    }
};

// with O(n) space
// class Solution {
// public:
//     int scoreOfParentheses(string s) {
//         int n = s.size();

//         vector<int> st;
//         int score = 0;
        
//         for(int i = 0 ; i < n ; i++){
//             if(s[i] == '('){
//                 st.push_back(score);
//                 score = 0;
//             }else{ // )
//                 if(s[i-1] == '('){ // ()
//                     score = st.back() + 1;
//                 }else{ // nested
//                     score = st.back() + (2 * score);
//                 }
//                 st.pop_back();
//             }
            
//         }
//         return score;
//     }
// };

int main(){
    Solution s1;
    string s = "((()))()";

    cout<<s1.scoreOfParentheses(s)<<endl;
    
    return 0;
}