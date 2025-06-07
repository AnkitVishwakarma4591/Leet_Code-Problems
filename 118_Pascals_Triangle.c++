# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> f;
        f.push_back(vector<int>(1, 1));
        for (int i = 0; i < numRows - 1; ++i) {
            vector<int> g;
            g.push_back(1);
            for (int j = 0; j < f[i].size() - 1; ++j) {
                g.push_back(f[i][j] + f[i][j + 1]);
            }
            g.push_back(1);
            f.push_back(g);
        }
        return f;
    }
};

int main(){
    Solution s1;
    int numRows = 5;
    vector<vector<int>> ans = s1.generate(numRows);
    for(auto val : ans){
        for(auto data : val){
            cout<<data<<" ";
        }
        cout<<endl;
    }

    return 0;
}