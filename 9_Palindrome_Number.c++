# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        long long result = 0;
        long long temp = x;
        while(x > 0){
            int rem = x % 10;
            result = (10 * result) + rem;
            x /= 10;
        }
        return result == temp;
    }
};

int main(){
    Solution s1;
    int x = -121;

    cout<<s1.isPalindrome(x)<<endl;
    
    return 0;
}