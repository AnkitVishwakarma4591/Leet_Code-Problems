# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
  
        int sum    = 0;
        int min_el = INT_MIN;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            min_el = max(min_el, nums[i]);
        }

        return n*min_el - sum;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {2,1,3};

    cout<<s1.minMoves(nums)<<endl;
    
    return 0;
}