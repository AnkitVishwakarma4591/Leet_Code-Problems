# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int ans = 0;
        int idx = 0;

        while(n > 0){
            if((n & 1) == 0){
                ans = ans | (1 << idx);
            }
            idx++;
            n >>= 1;
        }
        return ans;
    }
};


int main(){
    Solution s1;

    int n = 5;
    cout<<s1.bitwiseComplement(n)<<endl;
    
    return 0;
}