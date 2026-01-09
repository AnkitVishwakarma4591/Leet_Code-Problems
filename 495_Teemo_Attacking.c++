# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {

        // Optimize
        int total = 0;
        int n = timeSeries.size();

        for(int i = 0; i < n - 1; i++){
            total += min(duration, timeSeries[i+1] - timeSeries[i]);
        }

        return total + duration;

        // TLE occure
        // int n = timeSeries.size();
        // set<int> s;
        // for(int i = 0 ; i < n ; i++){
        //     int curVal = timeSeries[i];
        //     for(int j = 0 ; j < duration ; j++){
        //         s.insert(curVal);
        //         curVal++;
        //     }
        // }
        // return s.size();
    }
};

int main(){
    Solution s1;
    vector<int> timeSeries = {1,4};
    int duration = 2;

    cout<<s1.findPoisonedDuration(timeSeries, duration)<<endl;
    
    return 0;
}