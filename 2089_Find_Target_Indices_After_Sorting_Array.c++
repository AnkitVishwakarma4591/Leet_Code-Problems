# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        unordered_map<int, vector<int>> storeIdx;

        for(int i = 0 ; i < n ; i++){
            storeIdx[nums[i]].push_back(i);
        }

        return storeIdx[target];
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,5,2,3};
    int target = 2;

    for(int val : s1.targetIndices(nums, target)){
        cout<<val<<" ";
    }

    return 0;
}