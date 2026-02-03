# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return false;

        int i = 1;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        
        while(i < n && nums[i] > nums[i-1]){
            cnt1++;
            i++;
        }
        while(i < n && nums[i] < nums[i-1]){
            cnt2++;
            i++;
        }
        while(i < n && nums[i] > nums[i-1]){
            cnt3++;
            i++;
        }

        return cnt1 >=1 && cnt2 >= 1 && cnt3 >= 1 && i == n;   
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,3,5,4,2,6};

    cout<<s1.isTrionic(nums)<<endl;
    
    return 0;
}