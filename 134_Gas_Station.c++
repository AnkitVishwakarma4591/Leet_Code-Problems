# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0 , totalcost = 0;
        int start = 0, currgas = 0;

        for(int i = 0 ; i < gas.size() ; i++){
            totalgas += gas[i];
            totalcost += cost[i];
            currgas += (gas[i] - cost[i]);

            if(currgas < 0){
                start = i+1;
                currgas = 0;
            }
        }
        return totalgas < totalcost ? -1 : start;
    }
};


int main(){
    Solution s1;
    vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};

    cout<<s1.canCompleteCircuit(gas, cost)<<endl;
    
    return 0;
}