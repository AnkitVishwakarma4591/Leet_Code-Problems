#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 12345;

        int size = m * n;
        vector<int> arr;

        // Flatten matrix
        for (auto &row : grid) {
            for (int val : row) {
                arr.push_back(val % mod);
            }
        }

        vector<int> prefix(size, 1), suffix(size, 1);

        // Prefix product
        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % mod;
        }

        // Suffix product
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % mod;
        }

        // Build result matrix
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < size; i++) {
            int val = (prefix[i] * suffix[i]) % mod;
            ans[i / n][i % n] = val;
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {{12345}, {2}, {1}};

    Solution obj;
    vector<vector<int>> result = obj.constructProductMatrix(grid);

    // Print result
    for (auto &row : result) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}