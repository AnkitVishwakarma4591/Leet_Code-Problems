# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        auto convertToDayOfYear = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int totalDays = day;
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonths[i];
            }
            return totalDays;
        };
        
        int aliceArrival = convertToDayOfYear(arriveAlice);
        int aliceLeave = convertToDayOfYear(leaveAlice);
        int bobArrival = convertToDayOfYear(arriveBob);
        int bobLeave = convertToDayOfYear(leaveBob);
        
        int overlapStart = max(aliceArrival, bobArrival);
        int overlapEnd = min(aliceLeave, bobLeave);
        
        return max(0, overlapEnd - overlapStart + 1);
    }
};

int main(){
    Solution s1;
    string arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19";

    cout<<s1.countDaysTogether(arriveAlice, leaveAlice, arriveBob, leaveBob)<<endl;
    
    return 0;
}