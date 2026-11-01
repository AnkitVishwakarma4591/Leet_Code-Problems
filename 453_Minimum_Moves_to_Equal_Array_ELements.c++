# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum    = 0;
        int min_el = INT_MAX;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            min_el = min(min_el, nums[i]);
        }

        return sum - n*min_el;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,3};

    cout<<s1.minMoves(nums)<<endl;
    
    return 0;
}