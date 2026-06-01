# include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(cost.rbegin(), cost.rend());

        int total_sum = 0;
        for(int val : cost){
            total_sum += val;
        }
        int remains = 0;
        for(int i = 2 ; i < cost.size() ; i += 3){
            remains += cost[i];
        }

        return total_sum - remains;
    }
};

int main(){
    Solution s1;
    vector<int>  cost = {1, 2, 3};

    cout<<s1.minimumCost(cost)<<endl;
    
    return 0;
}