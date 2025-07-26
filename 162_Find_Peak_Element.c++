# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] > nums[mid + 1]) {
                end = mid;
            } else {
                st = mid + 1;
            }
        }

        return st; 
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,3,1};

    cout<<"Peak element at idx : "<<s1.findPeakElement(nums)<<endl;
    return 0;
}
