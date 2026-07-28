# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int mid = n/2;

        string str1 = s.substr(0,mid);
        sort(str1.begin(), str1.end());

        string str2 = str1;
        reverse(str2.begin(), str2.end());

        if(n % 2 != 0){
            return str1 + s[mid] + str2;
        }

        return str1 + str2;
        
    }
};

int main(){
    Solution s1;
    string s = "babab";
    
    cout<<s1.smallestPalindrome(s)<<endl;
    
    return 0;
}