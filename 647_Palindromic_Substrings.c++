# include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for(int center = 0; center < n; center++){
            // odd length
            int l = center, r = center;
            while(l >= 0 && r < n && s[l] == s[r]){
                count++;
                l--; r++;
            }

            // even length
            l = center, r = center + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                count++;
                l--; r++;
            }
        }
        return count;
    }
};

// Brute force 
// class Solution {
// public:
//     bool isPalindromic(string &s){
//         int n = s.size();
//         int st = 0, end = n-1;

//         while(st < end){
//             if(s[st] != s[end]){
//                 return false;
//             }
//             st++;
//             end--;
//         }
//         return true;
//     }
//     int countSubstrings(string s) {
//         int n = s.size();
//         int cnt = 0;

//         for(int i = 0 ; i < n ; i++){
//             string temp = "";
//             for(int j = i ; j < n ; j++){
//                 temp += s[j];
//                 if(isPalindromic(temp)){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
        
//     }
// };

int main(){
    Solution s1;
    string s = "abc";

    cout<<s1.countSubstrings(s)<<endl;

    return 0;
}