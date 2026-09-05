# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> min_val(n, 0);

        min_val[n-1] = nums[n-1];
        int curr_min = nums[n-1];

        for(int i = n-2 ; i >= 0 ; i--){
            curr_min = min(curr_min, nums[i]);
            min_val[i] = curr_min;
        }

        int curr_max = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            curr_max = max(curr_max, nums[i]);

            if (curr_max - min_val[i] <= k){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {5,0,1,4};
    int k = 3;

    cout<<s1.firstStableIndex(nums, k)<<endl;
    
    return 0;
}