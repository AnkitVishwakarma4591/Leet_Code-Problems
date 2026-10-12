# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9+7;

    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32, 0);

        for(int &num : nums) {
            for(int b = 0; b < 32; b++) {
                if(num & (1 << b)) {
                    count[b]++; //found a '1' in this bit position b
                }
            }
        }


        long long result = 0;

        while(k--) {
            long long curr = 0;

            for(int b = 0; b < 32; b++) {
                if(count[b] > 0) {
                    count[b]--;

                    curr = (curr | (1 << b));
                }
            }

            result = (result + (curr*curr)) % MOD;
        }

        return result;

    }
};


int main(){
    Solution s1;
    vector<int> nums = {2,6,5,8};
    int  k = 2;

    cout<<s1.maxSum(nums, k)<<endl;
    
    return 0;
}