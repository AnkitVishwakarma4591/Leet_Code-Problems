    # include <bits/stdc++.h>
    using namespace std;
    
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        vector<int> t;
        for (int k = 0; k < m + n - 1; ++k) {
            int i = k < n ? 0 : k - n + 1;
            int j = k < n ? k : n - 1;
            while (i < m && j >= 0)
                t.push_back(mat[i++][j--]);
            if (k % 2 == 0)
                reverse(t.begin(), t.end());
            for (int& v : t)
                ans.push_back(v);
            t.clear();
        }
        return ans;
    }

    int main(){
        vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};

        for(int val : findDiagonalOrder(nums)){
            cout<<val<<" ";
        }

        return 0;
    }