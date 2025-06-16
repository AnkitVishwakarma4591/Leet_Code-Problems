# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;

        // Simulate circular array by going from 2n-1 to 0
        for (int i = 2 * n - 1; i >= 0; --i) {
            int num = nums[i % n];
            while (!s.empty() && s.top() <= num) {
                s.pop();
            }
            if (i < n) {
                if (!s.empty())
                    ans[i] = s.top();
            }
            s.push(num);
        }

        return ans;
    }
};

int main(){

    Solution s1;
    vector<int> nums = {1,2,1};

    for(int val : s1.nextGreaterElements(nums)){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}