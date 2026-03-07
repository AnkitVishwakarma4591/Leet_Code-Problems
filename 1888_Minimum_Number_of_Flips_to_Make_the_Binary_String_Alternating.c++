# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        
        int n = s.length();
        string t = s + s;

        int ans1 = 0, ans2 = 0;
        int res = INT_MAX;

        for(int i = 0; i < t.length(); i++) {
            char ch = t[i];

            char expected1 = (i % 2 == 0) ? '0' : '1';
            char expected2 = (i % 2 == 0) ? '1' : '0';

            if(ch != expected1) ans1++;
            if(ch != expected2) ans2++;

            if(i >= n) {
                char prev = t[i - n];

                char prevExpected1 = ((i - n) % 2 == 0) ? '0' : '1';
                char prevExpected2 = ((i - n) % 2 == 0) ? '1' : '0';

                if(prev != prevExpected1) ans1--;
                if(prev != prevExpected2) ans2--;
            }

            if(i >= n - 1) {
                res = min(res, min(ans1, ans2));
            }
        }

        return res;
    }
};


int main(){
    Solution s1;
    string s = "1110";

    cout<<s1.minFlips(s)<<endl;
    
    return 0;
}