# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        vector<int> freq(100001, 0);

        for(int val : costs) {
            freq[val]++;
        }

        int ans = 0;

        for(int i = 1; i < 100001 && coins >= i; i++) {
            while(freq[i] > 0 && coins >= i) {
                ans++;
                freq[i]--;
                coins -= i;
            }
        }

        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> costs = {1,3,2,4,1};
    int coins = 7;

    cout<<s1.maxIceCream(costs, coins)<<endl;
    
    return 0;
}