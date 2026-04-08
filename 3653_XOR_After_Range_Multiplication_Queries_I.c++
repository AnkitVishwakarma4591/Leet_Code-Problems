# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        for(auto &arr : queries){
            long long int l = arr[0];
            long long int r = arr[1];
            long long int k = arr[2];
            long long int v = arr[3];

            for(int i = l ; i <= r ; i += k){
                nums[i] = (nums[i] * v) % mod;
            }
        }
        long long int ans = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            ans = ans ^ nums[i];
        }

        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,1,1};
    vector<vector<int>> queries = {{0,2,1,4}};

    cout<<s1.xorAfterQueries(nums, queries)<<endl;

    return 0;
}
