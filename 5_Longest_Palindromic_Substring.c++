# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPlaindrome(string &temp){
        int n = temp.size();
        int st = 0, end = n-1;

        while(st < end){
            if(temp[st] != temp[end]) return false;
            st++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans;
        int currSize = 0;
        for(int i = 0 ; i < n ; i++){
            string temp = "";
            for(int j = i ; j < n ; j++){
                temp += s[j];

                if(isPlaindrome(temp) && temp.size() > currSize){
                    ans = temp;
                    currSize = temp.size();
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;
    string s = "babad";

    cout<<s1.longestPalindrome(s)<<endl;
    
    return 0;
}