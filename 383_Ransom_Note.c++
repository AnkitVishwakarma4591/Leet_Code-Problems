    # include <bits/stdc++.h>
    using namespace std;
    
    bool canConstruct(string ransomNote, string magazine) {

        int n = magazine.size();
        vector<bool> check(n,true);

        for(int i = 0 ; i < ransomNote.size() ; i++){
            bool found = false;
            for(int j = 0 ; j < n ; j++){
                if(ransomNote[i] == magazine[j] && check[j]){
                    found = true;
                    check[j] = false;
                    break;
                }
            }
            if(!found) return false;
        }
        return true;
    }

    int main(){
        string ransomNote = "aa", magazine = "aab";

        cout<<canConstruct(ransomNote,magazine)<<endl;
        return 0;
    }