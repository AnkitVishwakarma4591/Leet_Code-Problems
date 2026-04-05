# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> first, last;

        for(int i = 0; i < nums.size(); i++){
            int val = nums[i];

            if(first.find(val) == first.end()){
                first[val] = i;   
            }

            last[val] = i;        
            freq[val]++;          
        }

        int degree = 0;
        for(auto &p : freq){
            degree = max(degree, p.second);
        }

        int ans = INT_MAX;

        for(auto &p : freq){
            if(p.second == degree){
                int val = p.first;
                int len = last[val] - first[val] + 1;
                ans = min(ans, len);
            }
        }

        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,2,3,1};

    cout<<s1.findShortestSubArray(nums)<<endl;
    return 0;
}