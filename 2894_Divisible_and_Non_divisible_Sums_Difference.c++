# include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divbyM = 0;
        int notdivbyM = 0;
        for(int i = 1 ; i <= n ; i++){
            if(i % m == 0) divbyM += i;
            else notdivbyM += i;
        }
        return notdivbyM - divbyM;
    }
};

int main(){
    Solution s1;
    int n = 10 , m = 3;
    cout<<s1.differenceOfSums(n, m)<<endl;

    return 0;
}