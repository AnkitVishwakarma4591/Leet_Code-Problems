# include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> val;
        for(int i = 0 ; i < words.size() ; i++){
            string ans = words[i];
            for(int j = 0 ; j < ans.size() ; j++){
                if(ans[j] == x){
                    val.push_back(i);
                    break;
                }
            }
        }
        return val;
    }
};

int main(){
    Solution s1;
    vector<string> words = {"abc","bcd","aaaa","cbc"};
    char x = 'a';

    for(int val : s1.findWordsContaining(words, x)){
        cout<<val<<" ";
    }

    return 0;
}