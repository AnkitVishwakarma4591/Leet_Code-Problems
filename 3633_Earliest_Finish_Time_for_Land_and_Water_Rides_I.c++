# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int min_finish_time = 2e9;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int land_end = landStartTime[i] + landDuration[i];
                int total_finish_land_first = max(land_end, waterStartTime[j]) + waterDuration[j];
                min_finish_time = min(min_finish_time, total_finish_land_first);

                int water_end = waterStartTime[j] + waterDuration[j];
                int total_finish_water_first = max(water_end, landStartTime[i]) + landDuration[i];
                min_finish_time = min(min_finish_time, total_finish_water_first);
            }
        }

        return min_finish_time;
    }
};

int main(){
    Solution s1;
    vector<int> landStartTime  = {2,8};
    vector<int> landDuration   = {4,1};
    vector<int> waterStartTime   = {6};
    vector<int> waterDuration   = {3};

    cout<<s1.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration)<<endl;
    return 0;
}