# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n-1;
        
        int resultIdx = 0;

        while(st <= end){

            while(st < end && nums[st] == nums[st+1]) st++; // skip duplicate from left
            while(end > st && nums[end] == nums[end-1]) end--; // skip duplicate from right

            int mid = st + (end - st)/2;

            if(nums[mid] < nums[resultIdx]){
                resultIdx = mid;
            }
            if(nums[mid] > nums[end]){
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return nums[resultIdx];
    }
};

int main(){
    Solution s1;
    vector<int> nums = {2,2,2,0,1};

    cout<<s1.findMin(nums)<<endl;
    
    return 0;
}