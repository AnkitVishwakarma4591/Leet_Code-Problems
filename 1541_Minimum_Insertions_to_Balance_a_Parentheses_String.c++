# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int result = 0; //insertions

        int count = 0;
        int i = 0;

        while(i < n) {
            if(s[i] == '(') {
                count++;
                i++;
            } else { //')'
                if(count > 0) {
                    count--;
                } else {
                    result++; //adding a '('
                }

                if(i+1 < n && s[i+1] == ')') {
                    i += 2;
                } else {
                    result++; //adding a ')'
                    i++;
                }
            }
        }

        return result + count*2;
    }
};

int main(){
    Solution s1;
    string s = "(()))";

    cout<<s1.minInsertions(s)<<endl;
    
    return 0;
}