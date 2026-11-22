# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        bool seenA = false;
        bool seenB = false;

        for(char c : s){
            if(c == 'a'){
                if(!seenB){
                    seenA = true;
                }else{
                    return false;
                }
            }else{
                seenB = true;
            }
        }
        return true;
    }
};

int main(){
    Solution s1;
    string s = "aaabbb";

    cout<<s1.checkString(s)<<endl;
    
    return 0;
}