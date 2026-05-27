# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> lowerCase(26, -1);
        vector<int> upparCase(26, -1);

        for(int i = 0 ; i < n ; i++){
            if(islower(word[i])){
                lowerCase[word[i] - 'a'] = i;
            }else{
                if(upparCase[word[i] - 'A'] == -1){
                    upparCase[word[i] - 'A'] = i;
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(lowerCase[i] != -1 && upparCase[i] != -1 && lowerCase[i] < upparCase[i]){
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;
    string word = "aaAbcBC";
    cout<<s1.numberOfSpecialChars(word)<<endl;
    return 0;
}