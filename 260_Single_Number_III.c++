# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(int val : nums){
            m[val]++;
        }

        for(auto num : m){
            if(num.second != 2){
                ans.push_back(num.first);
            }
        }
        return ans;

    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,1,3,2,5};

    vector<int> ans = s1.singleNumber(nums);

    for(int val : ans){
        cout<<val<<" ";
    }

    return 0;
}