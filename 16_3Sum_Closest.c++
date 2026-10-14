# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int closeSum = nums[0] + nums[1] + nums[2];

        int n = nums.size();

        for(int i = 0 ; i < n-2 ; i++){
            int left = i+1;
            int right = n-1;

            while(left < right){
                int currSum = nums[i] + nums[left] + nums[right];

                if(currSum == target){
                    return target;
                }

                if(abs(currSum - target) < abs(closeSum - target)){
                    closeSum = currSum;
                }

                if(currSum < target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return closeSum;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {-1,2,1,-4};
    int target = 1;

    cout<<s1.threeSumClosest(nums, target)<<endl;
    
    return 0;
}