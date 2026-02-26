# include <bits/stdc++.h>
using namespace std;

// Brute force approach

// class Solution {
// public:
//     int stepCount(int n){
//         int cnt = 0;
//         while(n != 1){
//             if(n % 2 == 0){
//                 n /= 2;
//                 cnt++;
//             }else{
//                 n += 1;
//                 // n /= 2;
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
    
//     int numSteps(string s) {
//         int n = s.size();
//         int decimal = 0;
//         int place = 1;
//         for(int i = n-1 ; i >= 0 ; i--){
//             if(s[i] == '1'){
//                 decimal += place * 1;
//             }
//             place *= 2;
//         }

//         return stepCount(decimal);
//     }
// };

// Optimal Approach
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        for(int i = s.size() - 1; i > 0; i--) {
            if((s[i] - '0' + carry) == 1) {
                steps += 2;   // add + divide
                carry = 1;
            } else {
                steps += 1;   // just divide
            }
        }

        return steps + carry;   // if carry remains
    }
};

int main(){
    Solution s1;
    string s = "1101";

    cout<<s1.numSteps(s)<<endl;
    
    return 0;
}