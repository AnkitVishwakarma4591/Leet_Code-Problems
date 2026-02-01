# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i + 1])
                cnt++;
        }

        // last and first element check
        if(nums[n - 1] > nums[0])
            cnt++;

        return cnt <= 1;
    }
};


int main(){
    Solution s1;
    vector<int> nums = {3,4,5,1,2};

    cout<<s1.check(nums)<<endl;
    
    return 0;
}