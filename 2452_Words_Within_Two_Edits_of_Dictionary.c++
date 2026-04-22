# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> result;

        for (string& query : queries) {
            
            for (string& s : dictionary) {
                int diff = 0;

                for (int i = 0; i < query.size(); i++) {
                    if (query[i] != s[i]) {
                        ++diff;
                    }

                    if(diff > 2)
                        break;
                }

                if (diff <= 2) {
                    result.push_back(query);
                    break;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s1;
    vector<string> queries = {"word","note","ants","wood"};
    vector<string> dictionary  = {"wood","joke","moat"};

    for(string val : s1.twoEditWords(queries, dictionary)){
        cout<<val<<" ";
    }
    
    return 0;
}