# include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    int countMost(vector<int>& nums, int goal){
        if(goal < 0) return 0;

        int l = 0, sum = 0, cnt = 0;

        for(int r = 0 ; r < nums.size() ; r++){
            sum += nums[r];

            while(sum > goal){
                sum -= nums[l++];
            }
            cnt += r-l+1;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countMost(nums,goal) - countMost(nums, goal-1);
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;

    cout<<s1.numSubarraysWithSum(nums, goal)<<endl;

    return 0;
}