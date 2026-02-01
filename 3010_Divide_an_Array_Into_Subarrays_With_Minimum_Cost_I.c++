# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // Brute force approach T.C = O(n log n) 

        // sort(nums.begin()+1, nums.end());
        // return nums[0] + nums[1] + nums[2];


        // Optimal approach T.C = O(N)

        int first = INT_MAX;
        int second = INT_MAX;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < first){
                second = first;
                first = nums[i];
            }
            else if(nums[i] < second){
                second = nums[i];
            }
        }

        return nums[0] + first + second;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,3,12};

    cout<<s1.minimumCost(nums)<<endl;
    
    return 0;
}