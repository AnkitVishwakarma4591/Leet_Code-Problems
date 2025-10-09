# include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n % 2 == 0){
            return n;
        }
        return n*2;
    }
};

int main(){
    Solution s1;
    int n = 5;
    cout<<s1.smallestEvenMultiple(n)<<endl;

    return 0;
}