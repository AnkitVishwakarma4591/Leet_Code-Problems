# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    int turnedOn;

    void solve(int pos, int h, int m, int count) {

        if(h >= 12 || m >= 60) 
            return;

        if(count == turnedOn) {
            string minute = (m < 10) ? "0" + to_string(m) : to_string(m);
            ans.push_back(to_string(h) + ":" + minute);
            return;
        }

        if(pos == 10) 
            return;

        if(pos < 4) {
            solve(pos + 1, h | (1 << pos), m, count + 1);
        } else {
            solve(pos + 1, h, m | (1 << (pos - 4)), count + 1);
        }

        solve(pos + 1, h, m, count);
    }

    vector<string> readBinaryWatch(int turnedOn) {
        this->turnedOn = turnedOn;
        ans.clear();
        solve(0, 0, 0, 0);
        return ans;
    }
};


int main(){
    Solution s1;
    int turnedOn = 1;

    for(auto val : s1.readBinaryWatch(turnedOn)){
        cout<<val<<" ";
    }
    return 0;
}