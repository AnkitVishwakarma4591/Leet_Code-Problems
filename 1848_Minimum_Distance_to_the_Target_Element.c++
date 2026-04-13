# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();

        int MinDis = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == target){
                MinDis = min(MinDis, abs(i-start));
            }
        }
        return MinDis;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,3,4,5};
    int target = 5, start = 3;

    cout<<s1.getMinDistance(nums, target, start)<<endl;
    
    return 0;
}