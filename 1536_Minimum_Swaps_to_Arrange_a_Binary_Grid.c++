# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> freq(n);

        
        for(int i = 0; i < n; i++) {
            int rowFreq = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j] == 0) {
                    rowFreq++;
                } else {
                    break;
                }
            }
            freq[i] = rowFreq;
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int req = n - i - 1;
            int idx = i;

            while(idx < n && freq[idx] < req) {
                idx++;
            }

            if(idx == n) return -1;

            while(i < idx) {
                swap(freq[idx - 1], freq[idx]);
                ans++;
                idx--;
            }
        }

        return ans;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> grid = {{0,0,1},{1,1,0},{1,0,0}};
    
    cout<<s1.minSwaps(grid)<<endl;

    return 0;
}