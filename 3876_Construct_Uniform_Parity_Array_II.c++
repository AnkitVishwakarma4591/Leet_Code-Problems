# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = nums1[0];
        bool has_odd = false, has_even = false;

        for (int val : nums1) {
            if (val % 2 != 0) has_odd = true;
            else has_even = true;
            
            min_val = min(min_val, val);
        }

        if (!has_odd || !has_even) return true;

        return min_val % 2 != 0;
    }
};


int main(){
    Solution s1;
    vector<int> nums1 = {1,4,7};

    cout<<s1.uniformArray(nums1)<<endl;
    
    return 0;
}