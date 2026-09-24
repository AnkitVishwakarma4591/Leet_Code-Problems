# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int DigitSum(int n){
        int sum = 0;

        while(n > 0){
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if(i == DigitSum(nums[i])){
                ans = min(ans, i);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,10,11};

    cout<<s1.smallestIndex(nums)<<endl;

    return 0;
}