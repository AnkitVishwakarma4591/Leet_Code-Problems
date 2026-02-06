# include <bits/stdc++.h>
using namespace std;

// TLE
// class Solution {
// public:
//     int minRemoval(vector<int>& nums, int k) {
//         int n = nums.size();

//         sort(nums.begin(), nums.end());

//         int i = 0, Max_cnt = 0;

//         while(i < n){
//             int j = i;
//             int limit = nums[i] * k;
//             int cnt = 0;
//             while(j < n){ 
//                 if(nums[j] <= limit){
//                     cnt++;
//                     j++;
//                 }else{
//                     break;
//                 }
//             }
//             Max_cnt = max(Max_cnt, cnt);
//             i++;
//         }
//        return n-Max_cnt;
//     }
// };

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int maxCnt = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < n && (long long)nums[j] <= (long long)nums[i] * k) {
                j++;
            }
            maxCnt = max(maxCnt, j - i);
        }

        return n - maxCnt;
    }
};



int main(){
    Solution s1;
    vector<int> nums = {1,6,2,9};
    int k = 3;

    cout<<s1.minRemoval(nums, k)<<endl;
    
    return 0;
}