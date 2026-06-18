# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hoursAngle = (30 * hour) + (0.5 * minutes);
        double minAngle = 6 * minutes;
        double angle = abs(hoursAngle - minAngle);

        return min(angle, 360 - angle);
    }
};

int main(){
    Solution s1;
    int hour = 12, minutes = 30;

    cout<<s1.angleClock(hour, minutes)<<endl;
    
    return 0;
}