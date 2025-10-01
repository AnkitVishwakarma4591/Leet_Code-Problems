# include <iostream>
# include<vector>
using namespace std;

/*
// Brute force approach
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        while(k > 0){
            vector<int> ans;
            ans.push_back(nums[n-1]);
            for(int i = 0 ; i < n-1 ; i++){
                ans.push_back(nums[i]);
            }
            nums = ans;
            k--;
        }
    }
};

*/

// better approach
class Solution {
public:
    vector<int> rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++){
            ans[(i+k)%n] = nums[i];
        }
        nums = ans;
        return nums;
    }
};

/*
// Optimal approach
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // ensure k is within array size

        reverse(nums.begin(), nums.end());          
        reverse(nums.begin(), nums.begin() + k);     
        reverse(nums.begin() + k, nums.end());       
    }
};
*/


int main(){
    Solution s1;
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    for(int val : s1.rotate(nums,k)){
        cout<<val<<" ";
    }

    return 0;
}