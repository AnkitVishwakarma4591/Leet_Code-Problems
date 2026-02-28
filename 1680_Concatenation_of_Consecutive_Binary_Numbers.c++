# include <bits/stdc++.h>
using namespace std;

// Brute force Approach

// class Solution {
// public:
//     string decimalToBinary(int n, string ans){
//         string temp = "";
        
//         while(n > 0){
//             temp = char((n % 2) + '0') + temp;
//             n /= 2;
//         }
        
//         return ans + temp;
//     }

//     int binaryToDecimal(string ans){
//         long long decimal = 0;
//         int mod = 1e9 + 7;

//         for(int i = 0; i < ans.size(); i++){
//             decimal = (decimal * 2 + (ans[i] - '0')) % mod;
//         }

//         return decimal;
//     } 

//     int concatenatedBinary(int n) {
//         string ans = "";

//         for(int i = 1 ; i <= n ; i++){
//             ans = decimalToBinary(i, ans);
//         }

//         return binaryToDecimal(ans);
//     }
// };

class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        int mod = 1e9 + 7;

        for(int i = 1; i <= n; i++){
            int length = log2(i) + 1;  // number of bits
            ans = ((ans << length) % mod + i) % mod;
        }

        return ans;
    }
};

int main(){
    Solution s1;

    int n = 12;

    cout<<s1.concatenatedBinary(n)<<endl;
    

    return 0;
}