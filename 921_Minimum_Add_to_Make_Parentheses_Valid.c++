# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int add = 0;

        for(char ch : s){
            if(ch == '('){
                open++;
            }else{
                if(open > 0){
                    open--;
                }else{
                    add++;
                }
            }
        }
        return open + add;
    }
};

int main(){
    Solution s1;
    string s = "()))((";

    cout<<s1.minAddToMakeValid(s)<<endl;
    
    return 0;
}