# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count_1(int n){
        int cnt = 0;
        while(n > 0){
            int rem = n % 2;
            if(rem == 1){
                cnt++;
            }
            n /= 2;
        }
        return cnt;
    }
    bool isPrime(int n){
        if(n <= 1) return false;
        if(n == 2) return true;
        for(int i = 2 ; i < n ; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int setbits = 0;
        for(int i = left ; i <= right ; i++){
            int cnt_1 = count_1(i);
            bool isPrime_bit = isPrime(cnt_1);
            if(isPrime_bit){
                setbits++;
            }
        }
        return setbits;
    }
};

int main(){
    Solution s1;
    int left = 6, right = 10;

    cout<<s1.countPrimeSetBits(left, right)<<endl;

    return 0;
}