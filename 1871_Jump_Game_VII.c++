# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();

        vector<int> t(n, 0);
        //t[i] > 0 : possible to reach i
        // == 0 : not possible to reach i

        t[0] = 1;
        int count = 0;

        for(int j = 1; j <= n-1; j++) {
            if(j - minJump >= 0) {
                count += t[j - minJump];
            }

            if(j - maxJump - 1 >= 0) {
                count -= t[j - maxJump - 1];
            }

            if(count > 0 && s[j] == '0') {
                t[j] = 1;
            }
        }

        return t[n-1] > 0;
    }
};


int main(){
    Solution s1;
    string s = "011010";
    int minJump = 2, maxJump = 3;

    cout<<s1.canReach(s, minJump, maxJump)<<endl;
    
    return 0;
}