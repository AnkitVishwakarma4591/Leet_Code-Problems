# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int F = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            F += i*nums[i];
        }

        int result = F;

        for(int k = 0; k <= n-1; k++) {
            int newF = F + sum - n*nums[n-1-k];

            result = max(result, newF);

            F = newF;
        }

        return result;
    }
};


// class Solution {
// public:
//     int maxRotateFunction(vector<int>& nums) {
//         int n = nums.size();
//         int result = INT_MIN;

//         int n1 = n;

//         while(n1 > 0){
//             int ans = 0;
//             int idx = 0;
//             for(int i = 0 ; i < n ; i++){
//                 ans += idx * nums[i];
//                 idx++;
//             }
//             result = max(result, ans);
//             vector<int> temp;
//             temp.push_back(nums[n-1]);
//             for(int i = 0 ; i < n-1 ; i++){
//                 temp.push_back(nums[i]);
//             }
//             nums = temp;
//             n1--;
//         }
//         return result;
//     }
// };

int main(){
    Solution s1;
    vector<int> nums = {4,3,2,6};

    cout<<s1.maxRotateFunction(nums)<<endl;
    
    return 0;
}