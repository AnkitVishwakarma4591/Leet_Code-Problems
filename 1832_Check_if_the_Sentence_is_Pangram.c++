# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> ch;
        for(auto val : sentence){
            if(isalpha(val)){
                ch.insert(tolower(val));
            }
        }
        return ch.size() == 26; 
    }
};

int main(){
    Solution s1;
    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    cout<<s1.checkIfPangram(sentence)<<endl;
    
    return 0;
}
