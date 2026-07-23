# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n == 1 || n == 2) return n;

        int ans = 1;
        while(ans <= n){
            ans *= 2;
        }
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2};

    cout<<s1.uniqueXorTriplets(nums)<<endl;
    
    return 0;
}