# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int pro = 1;
        int x = n;
        while(n > 0){
            int rem = n%10;
            sum += rem;
            pro *= rem;
            n /= 10;
        }

        int total = sum + pro;
        return (x%total == 0);
    }
};

int main(){
    Solution s1;
    int n = 99;
    
    cout<<s1.checkDivisibility(n)<<endl;

    return 0;
}