# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++){
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0)
                nums[idx] = -nums[idx];
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0)
                ans.push_back(i + 1);
        }
        return ans;



        // Brute force approach

        // unordered_map<int, int> m;
        // int n = nums.size();

        // for(int i = 1 ; i <= n ; i++){
        //     m[i]++;
        // }
        // for(int val : nums){
        //     m[val]++;
        // }
        // vector<int> ans;
        // for(auto num : m){
        //     if(num.second == 1){
        //         ans.push_back(num.first);
        //     }
        // }
        // return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {4,3,2,7,8,2,3,1};

    vector<int> ans = s1.findDisappearedNumbers(nums);
    for(int val : ans){
        cout<<val<<" ";
    }

    return 0;
}