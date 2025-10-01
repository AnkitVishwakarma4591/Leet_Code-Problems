# include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    int countMost(vector<int>& nums, int k){
        if(k < 0) return 0;
        int l = 0 , sum = 0, cnt = 0;

        for(int r = 0 ; r < nums.size() ; r++){
            sum += nums[r] % 2;
            while(sum > k){
                sum -= nums[l] % 2;
                l++;
            }
            cnt += r-l+1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countMost(nums,k) - countMost(nums,k-1);
        
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,1,2,1,1};
    int k = 3;

    cout<<s1.numberOfSubarrays(nums, k)<<endl;

    return 0;
}