# include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int minOperations(string s) {
//         int n = s.size();
//         int cnt = 0;

//         for(int i = 1; i < n; i++) {
//             if(s[i] == s[i-1]) {
//                 s[i] = (s[i] == '0') ? '1' : '0';
//                 cnt++;
//             }
//         }

//         return cnt;
//     }
// };

class Solution {
public:
    int countOperation(string s, bool start1) {
        int n = s.length();
        int count = 0;

        for(int i = 0; i < n; i++) {
            char ch = s[i];

            bool expected = (i % 2 == 0) ? start1 : !start1;

            if((expected && ch != '0') || (!expected && ch != '1')) {
                count++;
            }
        }

        return count;
    }

    int minOperations(string s) {
        return min(countOperation(s, true), countOperation(s, false));
    }
};

int main(){
    Solution s1;
    string s = "0100";

    cout<<s1.minOperations(s)<<endl;
    
    return 0;
}