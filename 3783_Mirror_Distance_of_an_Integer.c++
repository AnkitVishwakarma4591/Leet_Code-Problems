# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int n){
        int rev = 0;
        while(n > 0){
            int rem = n % 10;
            rev = rev * 10 + rem;
            n /= 10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};

int main(){
    Solution s1;
    int n = 25;
    cout<<s1.mirrorDistance(n)<<endl;
    
    return 0;
}