# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitProduct(int n){
        int pro = 1;

        while(n > 0){
            pro *= n%10;
            n /= 10;
        }
        return pro;
    }
    int smallestNumber(int n, int t) {
        while(digitProduct(n) % t != 0){
            n++;
        }

        return n;
    }
};

int main(){
    Solution s1;
    int n = 10, t = 2;

    cout<<s1.smallestNumber(n, t)<<endl;
    
    return 0;
}