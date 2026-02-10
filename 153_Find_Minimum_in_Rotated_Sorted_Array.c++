# include <iostream>
# include <vector>
# include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//        int m = INT_MAX;

//        for(int val : nums){
//         m = min(val,m);
//        } 
//        return m;
//     }
// };

class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, end = nums.size()-1;
        int ans = INT_MAX;

        while(st <= end){
            int mid = st + (end-st)/2;

            if(nums[st] <= nums[mid]){
                ans = min(ans, nums[st]);
                st = mid+1;
            }else{
                end = mid-1;
                ans = min(ans, nums[mid]);
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {3,4,5,1,2};

    cout<<s1.findMin(nums)<<endl;

    return 0;
}