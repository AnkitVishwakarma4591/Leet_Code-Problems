# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ones = 0;
        int twos = 0;
        for(auto num : nums){
            ones = (ones ^ num) & (~twos);
            twos = (twos ^ num) & (~ones);
        }
        return ones;

        
        // // Using Sorting Method
        // int n = nums.size();
        // if(n < 3) return nums[0];
        // sort(nums.begin(), nums.end());
        // if(nums[0] != nums[1]) return nums[0];

        // int i = 1;
        // while(i < n){
        //     if(nums[i] != nums [i-1]){
        //         return nums[i-1];
        //     }
        //     i += 3;
        // }
        // return nums[n-1];


        // Using Hash Map
        // unordered_map<int, int> m;
        // int ans;
        // for(int val : nums){
        //     m[val]++;
        // }

        // for(auto num : m){
        //     if(num.second != 3){
        //         ans = num.first;
        //     }
        // }
        // return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {0,1,0,1,0,1,99};

    cout<<s1.singleNumber(nums)<<endl;

    return 0;
}