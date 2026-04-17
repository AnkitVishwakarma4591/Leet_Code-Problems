# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getReverse(int n){
        int rev = 0;

        while(n > 0) {
            int rem = n % 10;
            rev = rev * 10 + rem;
            n /= 10;
        }

        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        int result = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            if(mp.count(nums[i])){
                result = min(result, i - mp[nums[i]]);
            }

            mp[getReverse(nums[i])] = i;
        }

        return result == INT_MAX ? -1 : result;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {12,21,45,33,54};

    cout<<s1.minMirrorPairDistance(nums)<<endl;
    
    return 0;
}