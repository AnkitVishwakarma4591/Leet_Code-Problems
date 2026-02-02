# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class KSmallestWindow {
    public:
        int k;
        long long sum = 0;
        int lowSize = 0, highSize = 0;

        map<int, int> low;   // k smallest
        map<int, int> high;  // rest

        KSmallestWindow(int k) : k(k) {}

        void addMap(map<int, int>& mp, int x) {
            mp[x]++;
        }

        bool removeMap(map<int, int>& mp, int x) {
            auto it = mp.find(x);
            if (it == mp.end()) return false;
            if (it->second == 1) mp.erase(it);
            else it->second--;
            return true;
        }

        int removeMaxLow() {
            auto it = prev(low.end());
            int x = it->first;
            removeMap(low, x);
            return x;
        }

        int removeMinHigh() {
            auto it = high.begin();
            int x = it->first;
            removeMap(high, x);
            return x;
        }

        void rebalance() {
            while (lowSize > k) {
                int x = removeMaxLow();
                lowSize--;
                sum -= x;
                addMap(high, x);
                highSize++;
            }

            while (lowSize < k && highSize > 0) {
                int x = removeMinHigh();
                highSize--;
                addMap(low, x);
                lowSize++;
                sum += x;
            }
        }

        void add(int x) {
            if (lowSize == 0 || x <= low.rbegin()->first) {
                addMap(low, x);
                lowSize++;
                sum += x;
            } else {
                addMap(high, x);
                highSize++;
            }
            rebalance();
        }

        void remove(int x) {
            if (removeMap(low, x)) {
                lowSize--;
                sum -= x;
            } else {
                removeMap(high, x);
                highSize--;
            }
            rebalance();
        }

        long long getSum() {
            return sum;
        }
    };

    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        if (k == 1) return nums[0];

        k--;  // nums[0] already fixed

        KSmallestWindow window(k);

        // initial window
        for (int i = 1; i <= dist + 1; i++) {
            window.add(nums[i]);
        }

        long long ans = window.getSum();

        // sliding window
        for (int i = 2; i + dist < n; i++) {
            window.remove(nums[i - 1]);
            window.add(nums[i + dist]);
            ans = min(ans, window.getSum());
        }

        return ans + nums[0];
    }
};


int main(){
    Solution s1;

    vector<int> nums = {1,3,2,6,4,2};
    int k = 3;
    int dist = 3;

    cout<<s1.minimumCost(nums, k, dist)<<endl;
    
    return 0;
}