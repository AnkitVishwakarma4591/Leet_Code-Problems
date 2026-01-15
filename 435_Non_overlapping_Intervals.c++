# include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(),
                [](vector<int>& a, vector<int>& b) {
                return a[1] < b[1];
            });

        int remove = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                remove++;
            } else {
                prevEnd = intervals[i][1];
            }
        }
        return remove;
    }
};


int main(){
    Solution s1;
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};

    cout<<s1.eraseOverlapIntervals(intervals)<<endl;
    
    return 0;
}