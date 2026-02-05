# include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int rightMove(int i, int k, int n){
//         return ((i + k) % n);
//     }
//     int leftMove(int i, int k, int n){
//         return ((i - (k % n) + n) % n);
//     }
//     vector<int> constructTransformedArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n);

//         for(int i = 0 ; i < n ; i++){
//             if(nums[i] > 0){
//                 int idx = rightMove(i, nums[i], n);
//                 ans[i] = nums[idx];
//             }else{
//                 int idx = leftMove(i, abs(nums[i]), n);
//                 ans[i] = nums[idx];
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int rightMove(int i, long long k, int n){
        return (i + k) % n;
    }

    int leftMove(int i, long long k, int n){
        return (i - (k % n) + n) % n;
    }

    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            long long k = nums[i];

            if(k > 0){
                int idx = rightMove(i, k, n);
                ans[i] = nums[idx];
            }else if(k < 0){
                k = -k; 
                int idx = leftMove(i, k, n);
                ans[i] = nums[idx];
            }else{
                ans[i] = nums[i];
            }
        }
        return ans;
    }
};


int main(){
    Solution s1;
    vector<int> nums = {3,-2,1,1};

    for(auto val : s1.constructTransformedArray(nums)){
        cout<<val<<" ";
    }
    
    return 0;
}