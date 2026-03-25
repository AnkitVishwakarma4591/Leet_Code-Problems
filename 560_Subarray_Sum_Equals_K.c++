# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];  
                if(sum == k) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,3};
    int k = 3;

    cout<<s1.subarraySum(nums, k)<<endl;
    
    return 0;
}