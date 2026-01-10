# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int cnt = 0;
        unordered_map<char, int> m;
        bool hasOdd = false;

        for(auto val : s){
            m[val]++;
        }

        for(auto twin : m){
            if(twin.second % 2 == 0){
                cnt += twin.second;
            }else{
                cnt += twin.second -1;
                hasOdd = true;
            }
        }
        
        if (hasOdd) cnt += 1;

        return cnt;
    }
};

int main(){
    Solution s1;
    string s = "abccccdd";
    cout<<s1.longestPalindrome(s)<<endl;
    
    return 0;
}