# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int val : nums) {
            if (val == first || val == second || val == third)
                continue;

            if (val > first) {
                third = second;
                second = first;
                first = val;
            } 
            else if (val > second) {
                third = second;
                second = val;
            } 
            else if (val > third) {
                third = val;
            }
        }

        // if third max doesn't exist
        if (third == LLONG_MIN)
            return first;

        return third;
    }
};

int main(){
    Solution s1;

    vector<int> nums = {3,2,1};

    cout<<s1.thirdMax(nums)<<endl;

    return 0;
}