# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    vector<ll> distance(vector<int>& nums) {
        int n = nums.size();

        vector<ll> arr(n, 0);

        unordered_map<int, ll> indexSum;   //nums[i] -> sum of i's
        unordered_map<int, ll> indexCount; //nums[i] -> frequency

        //Left to Right
        for(int i = 0; i < n; i++) {
            ll freq = indexCount[nums[i]];
            ll sum  = indexSum[nums[i]];

            arr[i] += freq*i - sum;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]]   += i;
        }

        indexSum.clear();
        indexCount.clear();

        //Right to Left
        for(int i = n-1; i >= 0; i--) {
            ll freq = indexCount[nums[i]];
            ll sum  = indexSum[nums[i]];

            arr[i] += sum - freq*i;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]]   += i;
        }

        return arr;
    }
};


// class Solution {
// public:
//     typedef long long ll;
//     vector<long long> distance(vector<int>& nums) {
//         int n = nums.size();
//         vector<ll> ans(n,0);

//         for(int i = 0 ; i < n ; i++){
//             int target = nums[i];
//             ll Sum = 0;

//             for(int j = 0 ; j < n ; j++){
//                 if(nums[j] == target &&  i != j){
//                     Sum += abs(i-j);
//                 }
//             }

//             ans[i] = Sum;
//         }

//         return ans;
//     }
// };

int main(){
    Solution s1;
    vector<int> nums = {1,3,1,1,2};

    for(int val : s1.distance(nums)){
        cout<<val<<" ";
    }
    return 0;
}