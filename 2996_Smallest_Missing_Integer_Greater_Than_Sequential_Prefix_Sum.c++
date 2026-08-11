# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        set<int> s;
        for(int val : nums){
            s.insert(val);
        }

        int prefixSum = nums[0];

        int i = 1;
        while(i < n && nums[i] == nums[i-1]+1){
            prefixSum += nums[i];
            i++;
        }

        while(s.find(prefixSum) != s.end()){
            prefixSum++;
        }

        return prefixSum;

    }
};

int main(){
    Solution s1;
    vector<int> nums = {3,4,5,1,12,14,13};

    cout<<s1.missingInteger(nums)<<endl;
    return 0;
}