# include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[node] = true;
        int n = isConnected.size();
        for(int j = 0; j < n; j++) {
            if(isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, isConnected, visited);
                provinces++;  // each DFS call finds a new province
            }
        }
        return provinces;
    }
};

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    Solution sol;
    int result = sol.findCircleNum(isConnected);
    cout << "Number of provinces: " << result << endl;

    return 0;
}