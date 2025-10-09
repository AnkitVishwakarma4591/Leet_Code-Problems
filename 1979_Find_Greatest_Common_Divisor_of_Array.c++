# include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int s = INT_MAX;
        int l = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            s = min(nums[i],s);
            l = max(nums[i],l);
        }

        while (l % s != 0) {
            int temp = l % s;
            l = s;
            s = temp;
        }

        return s;
    }
};

int main(){
    Solution s1;

    vector<int> nums = {2,5,6,9,10};

    cout<<s1.findGCD(nums)<<endl;

    return 0;
}