# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> result(seq.size());
        int d = 0;

        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] == '(') {
                d++;
                result[i] = d % 2 == 0 ? 1 : 0;
            } 
            else {
                result[i] = d % 2 == 0 ? 1 : 0;
                d--;
            }
        }

        return result;
    }
};


int main(){
    Solution s1;
    string seq = "(()())";
    
    for(auto val : s1.maxDepthAfterSplit(seq)){
        cout<<val<<" ";
    }

    return 0;
}