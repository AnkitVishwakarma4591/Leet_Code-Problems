# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(auto val : patterns){
            if(word.find(val) != string::npos){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    Solution s1;
    vector<string> patterns = {"a","abc","bc","d"};
    string word = "abc";

    cout<<s1.numOfStrings(patterns, word)<<endl;

    return 0;
}