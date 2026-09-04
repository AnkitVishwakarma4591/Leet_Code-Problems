# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            auto max_ele = max_element(nums.begin(), nums.begin()+i+1);
            auto min_ele = min_element(nums.begin()+i, nums.end());

            if(*max_ele - *min_ele <= k) return i;
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