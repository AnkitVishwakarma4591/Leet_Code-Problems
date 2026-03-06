# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '1' && (i == 0 || s[i-1] == '0')){
                cnt++;
            }
        }
        return cnt <= 1;
    }
};

int main(){
    Solution s1;
    string s = "1001";

    cout<<s1.checkOnesSegment(s)<<endl;
    
    return 0;
}