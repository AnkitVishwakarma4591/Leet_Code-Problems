# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();

        while(n > 0){
            string temp;
            for(int i = 1 ; i < s.size() ; i++){
                temp += s[i];
            }
            temp += s[0];

            s = temp;
            if(s == goal){
                return true;
            }
            n--;
        }
        return false;
    }
};

int main(){
    Solution s1;
    string s = "abcde", goal = "cdeab";
    
    cout<<s1.rotateString(s, goal)<<endl;
    
    return 0;
}