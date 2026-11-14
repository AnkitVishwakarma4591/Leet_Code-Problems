# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        int min_sum = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            int Sum = 0;
            for(int j = i ; j < n ; j++){
                Sum += nums[j];
                int size = (j-i+1);
                if((size >= l && size <= r) && Sum > 0){
                    min_sum = min(min_sum, Sum);
                }
            }
        }
        cout<<min_sum<<endl;
        return min_sum == INT_MAX ? -1 : min_sum;
    }
};

int main(){
    Solution s1;

    vector<int> nums = {3, -2, 1, 4};
    int l = 2;
    int r = 3;

    cout<<s1.minimumSumSubarray(nums, l, r)<<endl;
    
    return 0;
}