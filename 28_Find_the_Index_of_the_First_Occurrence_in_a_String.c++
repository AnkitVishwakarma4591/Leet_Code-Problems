# include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {

    int n = haystack.find(needle);

    return n;
    
}

int main(){
    string haystack = "sadbutsad", needle = "sad";
    cout<<strStr(haystack,needle)<<endl;
    
    return 0;
}