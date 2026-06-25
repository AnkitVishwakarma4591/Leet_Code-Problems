# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int subArrayCount = 0;
        
        for(int i = 0 ; i < n ; i++){
            int cnt = 0;
            int len = 0;
            for(int j = i ; j < n ; j++){
                if(nums[j] == target){
                    cnt++;
                }
                len++;
                
                // MOVE THIS INSIDE THE LOOP
                if(2 * cnt > len){
                    subArrayCount++;
                }
            }
        }
        return subArrayCount;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,2,3};
    int target = 2;

    cout<<s1.countMajoritySubarrays(nums, target)<<endl;
    
    return 0;
}