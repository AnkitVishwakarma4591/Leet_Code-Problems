# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // auto [minIt, maxIt] = minmax_element(nums.begin(), nums.end());
        // int Min = *minIt;
        // int Max = *maxIt;

        int Min = INT_MAX;
        int Max = INT_MIN;

        for(int val : nums){
            Min = min(Min, val);
            Max = max(Max, val);
        }

        // Approach 1 O(n logn)
        // sort(nums.begin(), nums.end());
        // vector<int> ans;
        // int j = 0;

        // for(int i = Min ; i <= Max ; i++){
        //     if(j < nums.size() && nums[j] == i){
        //         j++;
        //     }else{
        //         ans.push_back(i);
        //     }
            
        // }
        // return ans;

        // Approach O(n)
        unordered_set<int> present(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = Min ; i <= Max ; i++){
            if(present.find(i) == present.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,4,2,5};
    
    for(int val : s1.findMissingElements(nums)){
        cout<<val<<" ";
    }
    return 0;
}