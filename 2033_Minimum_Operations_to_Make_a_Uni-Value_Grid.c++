# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> temp;   // Correct size
        int rem = grid[0][0] % x;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] % x != rem) {
                    return -1;
                }
                temp.push_back(grid[i][j]);
            }
        }

        sort(temp.begin(), temp.end());

        int median = temp[temp.size() / 2];
        int ans = 0;

        for (int num : temp) {
            ans += abs(num - median) / x;
        }

        return ans;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> grid = {{2,4},{6,8}};
    int x = 2;

    cout<<s1.minOperations(grid, x)<<endl;

    return 0;
}