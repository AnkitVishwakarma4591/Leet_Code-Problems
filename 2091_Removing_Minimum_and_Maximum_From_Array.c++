# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minElIdx = min_element(nums.begin(), nums.end()) - begin(nums);
        int maxElIdx = max_element(nums.begin(), nums.end()) - begin(nums);

        int left = min(minElIdx, maxElIdx);
        int right = max(minElIdx, maxElIdx);
                // left del + right del , left del, right del
        return min({left+1+n-right, right+1, n-left});
    }
};

int main(){
    Solution s1;
    vector<int> nums = {2,10,7,5,4,1,8,6};

    cout<<s1.minimumDeletions(nums)<<endl;

    return 0;
}