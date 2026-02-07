# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(nums[0], nums[n - 1]);
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,5,2};

    cout<<s1.finalElement(nums)<<endl;
    
    return 0;
}
