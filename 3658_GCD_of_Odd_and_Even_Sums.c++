# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int GCD(int odd, int even){
        if(even == 0) return odd;

        return GCD(even, odd%even);
    }
    int gcdOfOddEvenSums(int n) {
        int oddCount = n;
        int oddSum = 0;
        int evenCount = n;
        int evenSum = 0;

        int i = 1, j = 1;
        while(oddCount > 0){
            if(i%2 != 0){
                oddSum += i;
                oddCount--;
            }
            i++;
        }
        while(evenCount > 0){
            if(j%2 == 0){
                evenSum += j;
                evenCount--;
            }
            j++;
        }

        return GCD(oddSum, evenSum);
    }
};

int main(){
    Solution s1;
    int n = 4;

    cout<<s1.gcdOfOddEvenSums(n)<<endl;
    
    return 0;
}