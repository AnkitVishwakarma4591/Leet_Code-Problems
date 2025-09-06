# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        vector<int> h(N), nextSmaller(N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                h[j] = A[i][j] == '0' ? 0 : (h[j] + 1);
            }
            stack<int> s;
            for (int j = N - 1; j >= 0; --j) {
                while (s.size() && h[j] <= h[s.top()]) s.pop();
                nextSmaller[j] = s.size() ? s.top() : N;
                s.push(j);
            }
            while(!s.empty()) s.pop();
            for (int j = 0; j < N; ++j) {
                while (s.size() && h[j] <= h[s.top()]) s.pop();
                int prevSmaller = s.size() ? s.top() : -1;
                ans = max(ans, (nextSmaller[j] - prevSmaller - 1) * h[j]);
                s.push(j);
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;

    vector<vector<char>> A = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
    };

    cout<<s1.maximalRectangle(A)<<endl;
    return 0;
}