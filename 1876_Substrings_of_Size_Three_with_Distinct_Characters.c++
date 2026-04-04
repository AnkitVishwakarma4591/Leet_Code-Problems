# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        int first = 0, second = 1;
        for(int i = 2 ; i < n ; i++){
            if(s[first] != s[second] && s[second] != s[i] && s[first] != s[i]){
                cnt++;
            }
            first = second;
            second = i;
        }
        return cnt;

    }
};

int main(){
    Solution s1;
    string s = "aababcabc";

    cout<<s1.countGoodSubstrings(s)<<endl;
    
    return 0;
}