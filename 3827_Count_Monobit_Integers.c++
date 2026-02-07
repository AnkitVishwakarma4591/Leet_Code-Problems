# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMonobit(int n) {
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            // 0 is special monobit
            if (i == 0) {
                cnt++;
            }
            // numbers like 1,3,7,15...
            else if ( ((i + 1) & i) == 0 ) {
                cnt++;
            }
        }
        return cnt;
    }
};


int main(){
    Solution s1;
    int n = 1;
    
    cout<<s1.countMonobit(n)<<endl;

    return 0;
}