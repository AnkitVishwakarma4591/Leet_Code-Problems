# include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0, l = 0, r = 0, zeros = 0;

        while(r < n){
            if(nums[r] == 0) zeros++;
            if(zeros > k){
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }
            if(zeros <= k){
                int len = r-l+1;
                maxLen = max(len,maxLen);
            }
            r++;
        }
        return maxLen;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int  k = 2;
    cout<<s1.longestOnes(nums,k)<<endl;
    return 0;
    
}