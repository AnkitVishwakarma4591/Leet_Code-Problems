# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int Max = 0;
        unordered_map<int, int> m;
        for(int val : nums){
            m[val]++;
        }
        for (auto &p : m) {
            int x = p.first;

            if (m.find(x + 1) != m.end()) {
                int add = p.second + m[x + 1];
                Max = max(Max, add);
            }
        }
        return Max;

    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,3,2,2,5,2,3,7};

    cout<<s1.findLHS(nums)<<endl;

    return 0;
}