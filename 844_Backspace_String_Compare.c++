# include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string buildResult(string s){
        string result = "";

        for(char ch : s){
            if(ch == '#'){
                if(result.size() != 0){
                    result.pop_back();
                }
            }else{
                result.push_back(ch);
            }
        }
        return result;
    }

    bool backspaceCompare(string s, string t){
        return buildResult(s) == buildResult(t);
    }
};

int main(){
    Solution s1;
    string s = "ab#c", t = "ad#c";

    cout<<s1.backspaceCompare(s, t)<<endl;
    
    return 0;
}