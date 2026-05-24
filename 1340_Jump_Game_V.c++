# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        // t[i] = maximum jumps starting from index i
        vector<int> t(n, 1);

        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({arr[i], i});
        }
        sort(begin(vec), end(vec));

        for (auto& it : vec) {
            int val = it.first;
            int i   = it.second;

            // move left
            for (int j = i - 1; j >= max(0, i - d); j--) {
                // same breaking condition
                if (arr[j] >= arr[i])
                    break;
                t[i] = max(t[i], 1 + t[j]);
            }

            // move right
            for (int j = i + 1; j <= min(n - 1, i + d); j++) {
                // same breaking condition
                if (arr[j] >= arr[i])
                    break;
                t[i] = max(t[i], 1 + t[j]);
            }
        }

        return *max_element(begin(t), end(t));
    }
};

int main(){
    Solution s1;
    vector<int> arr = {6,4,14,6,8,13,9,7,10,6,12};
    int d = 2;

    cout<<s1.maxJumps(arr, d)<<endl;
    
    return 0;
}