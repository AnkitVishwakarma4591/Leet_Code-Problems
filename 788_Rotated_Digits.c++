# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int num){
        bool canChange = false;

        while(num > 0){
            int digit = num % 10;

            if(digit == 3 || digit == 4 || digit == 7) return false;
            if(digit == 2 || digit == 5 || digit == 6 || digit == 9){
                canChange = true;
            }

            num /= 10;
        }
        return canChange;
    }
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++){
            if(isValid(i)){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    Solution s1;
    int n = 10;

    cout<<s1.rotatedDigits(n)<<endl;
    
    return 0;
}