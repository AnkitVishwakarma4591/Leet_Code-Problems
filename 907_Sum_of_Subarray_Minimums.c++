# include <iostream>
# include <vector>
# include <stack>
using namespace std;

// Brute Force Solution

// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
//         int sum = 0;
//         int mod = (int)(1e9+7);
//         for(int i = 0 ; i < n ; i++){
//             int m = arr[i];
//             for(int j = i ; j < n ; j++){
//                 m = min(m,arr[j]);
//                 sum = (sum + m) % mod;
//             }
//         }
//         return sum;
//     }
// };


// Optimal Solutions
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            ans += 1LL * (i - left[i]) * (right[i] - i) * arr[i] % mod;
            ans %= mod;
        }
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> arr = {3,1,2,4};
    cout<<s1.sumSubarrayMins(arr)<<endl;

    return 0;
}