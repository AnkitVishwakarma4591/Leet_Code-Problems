# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int start = nums[i];

            while(i + 1 < n && nums[i] + 1 == nums[i + 1]) {
                i++;
            }

            int end = nums[i];

            if(start == end) {
                ans.push_back(to_string(start));
            } else {
                ans.push_back(to_string(start) + "->" + to_string(end));
            }
        }

        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {0,1,2,4,5,7};

    for(auto st : s1.summaryRanges(nums)){
        cout<<st<<" ";
    }
    return 0;
}