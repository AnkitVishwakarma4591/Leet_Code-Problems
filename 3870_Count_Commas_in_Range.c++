# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCommas(int n) {
        int s = log10(n)+1;

        if(s <= 3){
            return 0;
        }

        return n-1000+1;
    }
};

int main(){
    Solution s1;
    int n = 1002;

    cout<<s1.countCommas(n)<<endl;
    
    return 0;
}