# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int Sum = 0;
        for(int i = 0 ; i < n ; i++){
            if(n % (i+1) == 0){
                Sum += nums[i] * nums[i];
            }
        }
        return Sum;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {2,7,1,19,18,3};

    cout<<s1.sumOfSquares(nums)<<endl;

    return 0;
}