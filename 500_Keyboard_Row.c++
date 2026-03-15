# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> first_row = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> second_row = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> third_row = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

        vector<string> ans;

        for(auto st : words){

            string lower = st;

            for(auto &c : lower) c = tolower(c);

            bool row1 = true, row2 = true, row3 = true;

            for(auto ch : lower){
                if(first_row.count(ch) == 0) row1 = false;
                if(second_row.count(ch) == 0) row2 = false;
                if(third_row.count(ch) == 0) row3 = false;
            }
            if(row1 || row2 || row3){
                ans.push_back(st);
            }
        }
        return ans;
    }
};


int main(){
    Solution s1;
    vector<string> words = {"Hello","Alaska","Dad","Peace"};

    for(auto st : s1.findWords(words)){
        cout<<st<<" ";
    }
    return 0;
}