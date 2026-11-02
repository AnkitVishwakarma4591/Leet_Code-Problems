# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n / 2];
        int moves = 0;
        
        for (int x : nums) {
            moves += abs(x - median);
        }
        
        return moves;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,3};

    cout<<s1.minMoves2(nums)<<endl;
    
    return 0;
}