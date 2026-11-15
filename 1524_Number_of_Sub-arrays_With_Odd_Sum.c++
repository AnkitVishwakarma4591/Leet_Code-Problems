# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int prefixSum = 0;
        
        // Start with evenCount = 1 to account for an empty prefix (sum = 0)
        int oddCount = 0;
        int evenCount = 1; 

        for (int num : arr) {
            prefixSum += num;
            
            if (prefixSum % 2 != 0) {
                ans = (ans + evenCount) % MOD;
                oddCount++;
            } else {
                ans = (ans + oddCount) % MOD;
                evenCount++;
            }
        }
        
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> arr = {1,3,5};

    cout<<s1.numOfSubarrays(arr)<<endl;
    
    return 0;
}