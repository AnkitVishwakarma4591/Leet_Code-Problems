# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cB = costBoth;
        long long n1 = need1, n2 = need2;
        
        long long totalCost = 0;
        
        long long common = min(n1, n2);
        totalCost += common * min(cB, c1 + c2);
        n1 -= common;
        n2 -= common;
        
        if (n1 > 0) {
            totalCost += n1 * min(cB, c1);
        }
        
        if (n2 > 0) {
            totalCost += n2 * min(cB, c2);
        }
        
        return totalCost;
    }
};

int main(){
    Solution s1;
    int cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2;

    cout<<s1.minimumCost(cost1, cost2, costBoth, need1, need2)<<endl;
    
    return 0;
}