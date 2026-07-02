# include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    typedef pair<int, pair<int,int>> P;

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        priority_queue<P, vector<P>, greater<P>> pq;

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        result[0][0] = grid[0][0]; //Source = {0, 0}
        pq.push({result[0][0], {0, 0}});

        while (!pq.empty()) {
            P curr = pq.top();
            int d = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;
            pq.pop();

            if (d > result[r][c]) continue;

            for (vector<int> &dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if (d + grid[nr][nc] < result[nr][nc]) {
                    result[nr][nc] = d + grid[nr][nc];
                    pq.push({result[nr][nc], {nr, nc}});
                }
            }
        }

        return health - result[m-1][n-1] >= 1;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> grid = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    int health = 1;

    cout<<s1.findSafeWalk(grid, health)<<endl;
    
    return 0;
}