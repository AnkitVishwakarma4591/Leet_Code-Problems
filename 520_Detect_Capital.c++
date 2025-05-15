# include <bits/stdc++.h>
using namespace std;

bool detectCapitalUse(string word){
    int capitalCount = 0 ; 
    int n = word.length();

    for(char c : word){
        if(isupper(c)){
            capitalCount++;
        }
    }

    if(capitalCount == n || capitalCount == 0 || (capitalCount == 1 && isupper(word[0]))){
        return true;
    }

    return false;
}

int main(){
    string word = "USA";
    cout<<detectCapitalUse(word)<<endl;
    return 0;
}