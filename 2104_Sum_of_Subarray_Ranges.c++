# include <bits/stdc++.h>
using namespace std;


// Brute force Solution
/*
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        for(int i = 0 ; i < n ; i++){
            int small = nums[i];
            int large = nums[i];
            for(int j = i ; j < n ; j++){
                small = min(small,nums[j]);
                large = max(large,nums[j]);

                sum += large - small;
            }
        }
        return sum;
    }
};*/


//Optimal sol
class Solution {
public:
    long long sumofSubarrayMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> stk;

        // Previous smaller
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty())
                left[i] = stk.top();
            stk.push(i);
        }

        // Next smaller
        while (!stk.empty())
            stk.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (!stk.empty())
                right[i] = stk.top();
            stk.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += 1LL * (i - left[i]) * (right[i] - i) * arr[i];
        }
        return ans;
    }

    long long sumofSubarrayMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> stk;

        // Previous greater
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] <= arr[i]) {
                stk.pop();
            }
            if (!stk.empty())
                left[i] = stk.top();
            stk.push(i);
        }

        // Next greater
        while (!stk.empty())
            stk.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] < arr[i]) {
                stk.pop();
            }
            if (!stk.empty())
                right[i] = stk.top();
            stk.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += 1LL * (i - left[i]) * (right[i] - i) * arr[i];
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& arr) {
        long long small = sumofSubarrayMin(arr);
        long long large = sumofSubarrayMax(arr);
        return large - small;
    }
};

int main(){
    Solution s1;
    vector<int> arr = {1,2,3};

    cout<<s1.subArrayRanges(arr)<<endl;

    return 0;
}