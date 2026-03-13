# include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPossible(long long mid, long long mh, vector<int>& workerTimes) {

        for(int wt : workerTimes) {

            long long k = (2LL * mid) / wt;
            long long x = (long long)((sqrt(1 + 4.0 * k) - 1) / 2);

            mh -= x;

            if(mh <= 0) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        long long low = 0;
        long long high = 1e18;
        long long ans = 0;

        while(low <= high) {

            long long mid = low + (high - low) / 2;

            if(isPossible(mid, mountainHeight, workerTimes)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main(){
    Solution s1;

    int mountainHeight = 4;
    vector<int> workerTimes  = {2,1,1};

    cout<<s1.minNumberOfSeconds(mountainHeight, workerTimes)<<endl;
    
    return 0;
}