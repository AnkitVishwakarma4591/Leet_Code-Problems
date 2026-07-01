# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {-1,0}, {1,0}};

    int maximumSafenessFactor(vector<vector<int>>& mat) {
        int n = mat.size();

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, -1));

        // Collect all thief cells as BFS sources
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // Multi-source BFS: compute minimum distance to nearest thief
        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();
            int x = cell.first;
            int y = cell.second;

            for (auto &d : dir) {
                int r = x + d[0];
                int c = y + d[1];

                if (r < 0 || r >= n || c < 0 || c >= n || dist[r][c] != -1)
                    continue;

                dist[r][c] = dist[x][y] + 1;
                q.push({r, c});
            }
        }

        // Max-heap: {safeness, x, y}
        priority_queue<vector<int>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pq.push({dist[0][0], 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int sfac = curr[0];
            int x = curr[1];
            int y = curr[2];

            if (visited[x][y])
                continue;
            visited[x][y] = true;

            if (x == n - 1 && y == n - 1)
                return sfac;

            for (auto &d : dir) {
                int r = x + d[0];
                int c = y + d[1];

                if (r < 0 || r >= n || c < 0 || c >= n || visited[r][c])
                    continue;

                int mn = min(sfac, dist[r][c]);
                pq.push({mn, r, c});
            }
        }

        return 0;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> grid = {{1,0,0},{0,0,0},{0,0,1}};

    cout<<s1.maximumSafenessFactor(grid)<<endl;
    
    return 0;
}
