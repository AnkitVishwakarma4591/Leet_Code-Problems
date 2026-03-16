#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> grid;

    vector<vector<int>> dr, dl;

    bool isValid(int r, int c, int k) {
        return (r - k) >= 0 && (r + k) < m && (c - k) >= 0 && (c + k) < n;
    }

    void initPrefix() {
        dr.assign(m, vector<int>(n, 0));
        dl.assign(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                dr[i][j] = grid[i][j];
                if(i > 0 && j > 0)
                    dr[i][j] += dr[i - 1][j - 1];

                dl[i][j] = grid[i][j];
                if(i > 0 && j < n - 1)
                    dl[i][j] += dl[i - 1][j + 1];
            }
        }
    }

    int getRhombusSum(int r, int c, int k) {

        if(k == 0) return grid[r][c];

        int sum = 0;

        // top → right
        sum += dr[r][c + k] - ((r - k - 1 >= 0 && c - 1 >= 0) ? dr[r - k - 1][c - 1] : 0);

        // right → bottom
        sum += dl[r + k][c] - ((r - 1 >= 0 && c + k + 1 < n) ? dl[r - 1][c + k + 1] : 0);

        // bottom → left
        sum += dr[r + k][c] - ((r - 1 >= 0 && c - k - 1 >= 0) ? dr[r - 1][c - k - 1] : 0);

        // left → top
        sum += dl[r][c - k] - ((r - k - 1 >= 0 && c + 1 < n) ? dl[r - k - 1][c + 1] : 0);

        sum -= grid[r - k][c];
        sum -= grid[r][c + k];
        sum -= grid[r + k][c];
        sum -= grid[r][c - k];

        return sum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& g) {

        grid = g;
        m = grid.size();
        n = grid[0].size();

        initPrefix();

        set<int> tSet;

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {

                int k = 0;
                while(isValid(r, c, k)) {

                    int sum = getRhombusSum(r, c, k);
                    tSet.insert(sum);

                    if(tSet.size() > 3)
                        tSet.erase(tSet.begin());

                    k++;
                }
            }
        }

        vector<int> ans;
        for(auto it = tSet.rbegin(); it != tSet.rend(); it++) {
            ans.push_back(*it);
        }

        return ans;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> grid = {{3, 4, 5, 1, 3},{3, 3, 4, 2, 3},{20, 30, 200, 40, 10},{1, 5, 5, 4, 1},{4, 3, 2, 2, 5}};

    for(int val : s1.getBiggestThree(grid)){
        cout<<val<<" ";
    }
}