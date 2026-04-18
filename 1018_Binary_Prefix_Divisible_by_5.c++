# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int current_remainder = 0;
        
        for (int bit : nums) {
            current_remainder = (current_remainder * 2 + bit) % 5;
            
            ans.push_back(current_remainder == 0);
        }
        
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {0,1,1};

    for(auto val : s1.prefixesDivBy5(nums)){
        cout<<val<<" ";
    }
    return 0;
}