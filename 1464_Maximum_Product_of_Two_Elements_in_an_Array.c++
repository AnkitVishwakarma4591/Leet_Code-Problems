# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        return ((nums[n-1]-1) * (nums[n-2]-1));
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,5,4,5};

    cout<<s1.maxProduct(nums)<<endl;
    
    return 0;
}