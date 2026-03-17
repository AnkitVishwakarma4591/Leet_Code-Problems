# include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isMonotonic(vector<int> &nums){
        int n = nums.size();
        bool inc = true, dec = true;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] > nums[i-1]) inc = false;
            if(nums[i] < nums[i-1]) dec = false;
        }
        return inc || dec;
    }
};
int main(){
    Solution s1;
    vector<int> nums = {1,2,2,3};

    cout<<s1.isMonotonic(nums)<<endl;
    
    return 0;
}