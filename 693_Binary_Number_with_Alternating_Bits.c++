# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s = "";
        while(n > 0){
            int rem = n % 2;
            s += rem + '0';
            n /= 2;
        }
        char prev = s[0];
        for(int i = 1 ; i < s.size() ; i++){
            if(prev == s[i]) return false;
            prev = s[i];
        }
        return true;
    }
};

int main(){
    Solution s1;
    int n = 11;

    cout<<s1.hasAlternatingBits(n)<<endl;
    
    return 0;
}