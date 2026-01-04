# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            if(i > maxIdx) return false;
            maxIdx = max(maxIdx, i + nums[i]);
        }
        return true;
    }
};


int main(){
    Solution s1;
    vector<int> nums = {2,3,1,1,4};

    cout<<s1.canJump(nums)<<endl;
    
    return 0;
}