# include<bits\stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

int main(){
    Solution s1;
    int n = 27;

    cout<<s1.isPowerOfThree(n)<<endl;
    return 0;
}