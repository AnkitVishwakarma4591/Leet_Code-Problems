# include <bits/stdc++.h>
using namespace std;

// // Brute force approach

// class Solution {
// public:
//     string addBinary(string a, string b) {
//         int n = a.size();
//         int m = b.size();
        
//         string ans = "";
//         char carry = '0';   
        
//         while(n > 0 || m > 0 || carry == '1') {
            
//             char bitA = (n > 0) ? a[n-1] : '0';
//             char bitB = (m > 0) ? b[m-1] : '0';
            
//             char write;
            
//             if(bitA == '0' && bitB == '0' && carry == '0'){
//                 write = '0'; carry = '0';
//             }
//             else if(bitA == '0' && bitB == '0' && carry == '1'){
//                 write = '1'; carry = '0';
//             }
//             else if(bitA == '1' && bitB == '1' && carry == '1'){
//                 write = '1'; carry = '1';
//             }
//             else if(bitA == '1' && bitB == '1' && carry == '0'){
//                 write = '0'; carry = '1';
//             }
//             else { 
//                 if(carry == '0'){
//                     write = '1'; carry = '0';
//                 } else {
//                     write = '0'; carry = '1';
//                 }
//             }
            
//             ans += write;
            
//             if(n > 0) n--;
//             if(m > 0) m--;
//         }
        
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

// Better Approach
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size() - 1;
        int m = b.size() - 1;
        int carry = 0;
        string ans = "";

        while(n >= 0 || m >= 0 || carry) {
            int sum = carry;

            if(n >= 0) sum += a[n--] - '0';
            if(m >= 0) sum += b[m--] - '0';

            ans += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main(){
    Solution s1;
    string a = "1010";
    string b = "1011";

    cout<<s1.addBinary(a, b)<<endl;
    
    return 0;
}