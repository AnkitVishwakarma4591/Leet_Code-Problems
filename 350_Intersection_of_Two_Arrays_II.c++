# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        vector<int> ans;

        for (int x : nums1)
            freq[x]++;

        for (int x : nums2) {
            if (freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
        }
        return ans;
    }
};


int main(){
    Solution s1;
    vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
    vector<int> ans = s1.intersect(nums1, nums2);
    for(auto val : ans){
        cout<<val<<" ";
    }
    return 0;
}