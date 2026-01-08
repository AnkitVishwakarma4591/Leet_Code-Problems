# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < nums.size() ; i += 2){
            sum += nums[i];
        }
        return sum;
    }
};


int main(){
    Solution s1;
    vector<int> nums = {1,4,3,2};

    cout<<s1.arrayPairSum(nums)<<endl;
    
    return 0;
}