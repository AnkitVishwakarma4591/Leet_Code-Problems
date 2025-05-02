# include <bits/stdc++.h>
using namespace std;

char findTheDifference(string s, string t){
    char ans = 0;

    for(char c : s){
        ans ^= c;
    }
    for(char c : t){
        ans ^= c;
    }
    return ans;
}

int main(){
    string s = "abcd";
    string t = "abcde";

    cout<<findTheDifference(s,t)<<endl;
    
    return 0;
}