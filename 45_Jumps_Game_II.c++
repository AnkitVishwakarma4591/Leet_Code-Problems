# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0, r = 0;

        while (r < n - 1) {
            int fastest = 0;

            for (int i = l; i <= r; i++) {
                fastest = max(fastest, i + nums[i]);
            }

            l = r + 1;
            r = fastest;
            jumps++;
        }

        return jumps;
    }
};


int main(){
    Solution s1;

    vector<int> nums = {2,3,1,1,4};

    cout<<s1.jump(nums)<<endl;

    return 0;
}