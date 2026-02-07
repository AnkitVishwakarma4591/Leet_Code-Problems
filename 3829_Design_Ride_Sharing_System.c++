# include <bits/stdc++.h>
using namespace std;

class RideSharingSystem {
private:
    queue<int> ridersQ;
    queue<int> driversQ;
    unordered_set<int> activeRiders;

public:
    RideSharingSystem() {}

    void addRider(int riderId) {
        ridersQ.push(riderId);
        activeRiders.insert(riderId);
    }

    void addDriver(int driverId) {
        driversQ.push(driverId);
    }

    vector<int> matchDriverWithRider() {
        // Remove invalid riders
        while (!ridersQ.empty() && activeRiders.count(ridersQ.front()) == 0) {
            ridersQ.pop();
        }

        if (ridersQ.empty() || driversQ.empty()) {
            return {-1, -1};
        }

        int driverId = driversQ.front();
        driversQ.pop();

        int riderId = ridersQ.front();
        ridersQ.pop();
        activeRiders.erase(riderId); // mark as matched

        return {driverId, riderId};
    }

    void cancelRider(int riderId) {
        // Just invalidate; actual removal happens lazily
        activeRiders.erase(riderId);
    }
};


int main(){
    RideSharingSystem r1;
    
    return 0;
}