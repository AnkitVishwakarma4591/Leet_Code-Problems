# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxEl = INT_MIN;
        int minEl = INT_MAX;

        for(int &num : nums) {
            maxEl = max(maxEl, num);
            minEl = min(minEl, num);
        }

        return 1LL*(maxEl - minEl)*k;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,3};
    int k = 2;
    cout<<s1.maxTotalValue(nums, k)<<endl;
    
    return 0;
}