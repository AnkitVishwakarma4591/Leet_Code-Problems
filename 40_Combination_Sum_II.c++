# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, 
               vector<int>& temp, vector<vector<int>>& ans) {
        
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            
            if(i > idx && candidates[i] == candidates[i-1]) continue;

            if(candidates[i] > target) break;

            temp.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i], temp, ans);
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, candidates, target, temp, ans);

        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    for(auto val : s1.combinationSum2(candidates, target)){
        for(int i : val){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}