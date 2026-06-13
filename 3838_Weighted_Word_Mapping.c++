# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int, char> map;
        int idx = 0;
        for(char i = 'z' ; i >= 'a' ; i--){
            map[idx++] = i;
        }

        string ans = "";
        for(auto &str : words){
            int Sum = 0;
            for(char &ch : str){
                Sum += weights[ch - 'a'];
            }
            ans += map[Sum%26];
        }
        return ans;
    }
};

int main(){
    Solution s1;
    vector<string> words = {"abcd","def","xyz"};
    vector<int> weights = {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2};

    cout<<s1.mapWordWeights(words, weights)<<endl;
    
    return 0;
}