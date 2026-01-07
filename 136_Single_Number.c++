# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int val : nums){
            ans = ans ^ val;
        }
        return ans;

        // Using Hash Map
        // int ans = 0;
        // unordered_map<int,int> m;
        // for(auto val : nums){
        //     m[val]++;
        // }
        // for(auto num : m){
        //     if(num.second != 2){
        //         ans = num.first;
        //     }
        // }
        // return ans;
        
    }
};

int main(){
    Solution s1;
    vector<int> nums = {4,1,2,1,2};
    cout<<s1.singleNumber(nums)<<endl;
    
    return 0;
}