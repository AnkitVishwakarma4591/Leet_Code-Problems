# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            int val = nums[i];

            string num = to_string(val);
            for(char ch : num){
                ans.push_back(ch - '0');
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {13,25,83,77};

    for(int val : s1.separateDigits(nums)){
        cout<<val<<" ";
    }
    return 0;
}