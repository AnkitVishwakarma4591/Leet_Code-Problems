# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(char &ch : s){
            if(isalpha(ch) && islower(ch)){
                result.push_back(ch);
            }else if(ch == '*' && !result.empty()){
                result.pop_back();
            }else if(ch == '#'){
                result += result;
            }else if(ch == '%'){
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};

int main(){
    Solution s1;
    string s = "a#b%*";

    cout<<s1.processStr(s)<<endl;

    return 0;
}