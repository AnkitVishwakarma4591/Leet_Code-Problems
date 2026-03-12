#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;

    int find(int idx) {
        if(parent[idx] == idx) return idx;
        return parent[idx] = find(parent[idx]);
    }

    int isPossible(int mid, vector<vector<int>>& edges, int n, int k) {

        parent.assign(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;

        int currAns = INT_MAX;
        int edgeCnt = 0;

        for(auto &edge : edges) {
            int ui = edge[0];
            int vi = edge[1];
            int si = edge[2];

            int pu = find(ui);
            int pv = find(vi);

            if(edge[3] == 1) {
                if(si < mid || pu == pv) return INT_MAX;

                edgeCnt++;
                parent[pu] = pv;
                currAns = min(currAns, si);

            } else if(pu != pv) {

                if(si >= mid) {
                    edgeCnt++;
                    parent[pu] = pv;
                    currAns = min(currAns, si);

                } else if(k > 0 && si * 2 >= mid) {
                    edgeCnt++;
                    parent[pu] = pv;
                    currAns = min(currAns, si * 2);
                    k--;
                }
            }
        }

        return edgeCnt == n - 1 ? currAns : INT_MAX;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            if(a[3] != b[3])
                return a[3] > b[3];
            return a[2] > b[2];
        });

        int ans = -1;
        int low = 1, high = 100050;

        while(low <= high) {
            int mid = (low + high) / 2;

            int minSi = isPossible(mid, edges, n, k);

            if(minSi != INT_MAX) {
                ans = minSi;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    int n = 3;
    vector<vector<int>> edges = {
        {0,1,2,1},
        {1,2,3,0}
    };

    int k = 1;

    Solution obj;
    cout << obj.maxStability(n, edges, k) << endl;

    return 0;
}