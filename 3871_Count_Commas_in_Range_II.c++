# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    long long countCommas(long long n) {
        ll result = 0;
        ll lower = 1000;
        ll commas = 1;

        while(lower <= n){
            ll upper = lower*1000-1;
            if(upper > n) upper = n;

            ll countNum = upper - lower + 1;

            result += (countNum * commas);

            lower *= 1000;
            commas++;
        }

        return result;
    }
};

int main(){
    Solution s1;
    ll n = 1002;
    
    cout<<s1.countCommas(n)<<endl;

    return 0;
}