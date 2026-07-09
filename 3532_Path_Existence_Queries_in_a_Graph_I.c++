# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, -1);
        int compId = 0;
        component[0] = compId;

        for(int i = 1 ; i < n ; i++){
            if(nums[i] - nums[i-1] > maxDiff){
                compId++;
            }
            component[i] = compId;
        }

        vector<bool> result;
        for(auto &q : queries){
            int u = q[0];
            int v = q[1];
            result.push_back(component[u] == component[v]);
        }
        return result;
    }
};

int main(){
    Solution s1;
    int n = 2;
    vector<int> nums = {1,3};
    int maxDiff = 1;
    vector<vector<int>> queries = {{0,0}, {0, 1}};

    for(auto val : s1.pathExistenceQueries(n, nums, maxDiff, queries)){
        cout<<val<<" ";
    }
    return 0;
}