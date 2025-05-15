# include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s){
    int n = s.length();

    for(int i = 0 ; i < n ; i++){
        bool isUnique = true;

        for(int j = 0 ; j < n ; j++){
            if(i != j && s[i] == s[j]){
                isUnique = false;
                break;
            }
        }

        if(isUnique == true){
            return i;
        }
    }
    return -1;
}

int main(){
    string s = "leetcode";

    cout<<firstUniqChar(s)<<endl;

    return 0;
}