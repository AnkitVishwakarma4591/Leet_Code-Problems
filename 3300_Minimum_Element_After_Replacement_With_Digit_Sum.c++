# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n > 0){
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MAX;
        for(int val : nums){
            ans = min(ans, digitSum(val));
        }

        return ans;
    }
};


int main(){
    Solution s1;
    vector<int> nums = {10, 12, 13, 14};

    cout<<s1.minElement(nums)<<endl;
    
    return 0;
}