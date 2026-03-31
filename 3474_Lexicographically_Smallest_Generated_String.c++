# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSame(string &word, string &str2, int i, int m){
        for(int j = 0 ; j < m ; j++){
            if(word[i] != str2[j]){
                return false;
            }
            i++;
        }
        return true;
    }
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        int N = (n+m-1);

        string word(N, '$');

        vector<bool> canChange(N, false);

        // Process the 'T'
        for(int i = 0 ; i < n ; i++){
            if(str1[i] == 'T'){
                int i_ = i;
                for(int j = 0 ; j < m ; j++){
                    // word[i] = str2 [j]
                    // word[i+1] = str2 [j+1]...
                    if(word[i_] != '$' && word[i_] != str2[j]){
                        return "";
                    }
                    word[i_] = str2[j];
                    i_++;
                }
            }
            
        }

        // Fill the remaining spaces with 'a'
        for(int i = 0 ; i < N ; i++){
            if(word[i] == '$'){
                word[i] = 'a';
                canChange[i] = true;
            }
        }

        // Process the 'F
        for(int i = 0 ; i < n ; i++){
            if(str1[i] == 'F'){
                if(isSame(word, str2, i, m)){ //if same, then we need to make it unequal

                bool changed = false;
                for(int j = i+m-1 ; j >= i ; j--){
                    if(canChange[j] == true){
                        word[j] = 'b';
                        changed = true;
                        break;
                    }
                }

                if(changed == false){ // i was not able to change any character to break equal
                    return "";
                }

                }
            }
        }
        return word;
    }
};

int main(){
    Solution s1;
    string str1 = "TFTF", str2 = "ab";

    cout<<s1.generateString(str1, str2)<<endl;

    return 0;
}