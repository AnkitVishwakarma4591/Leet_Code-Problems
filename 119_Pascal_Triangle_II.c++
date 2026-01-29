# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int nCr(int n, int r){
    //     long long int res = 1;
    //     for(int i = 0 ; i < r ; i++){
    //         res = res * (n-i);
    //         res = res/(i+1);
    //     }
    //     return res;
    // }
    // vector<int> getRow(int rowIndex) {
    //     int n = rowIndex+1;
    //     vector<int> ans;
    //     for(int c = 1 ; c <= n ; c++){
    //         ans.push_back(nCr(n-1, c-1));
    //     }
    //     return ans;
    // }
    
    // Optimal Solution
    vector<int> getRow(int rowIndex){
        vector<int> nthrow;
        long long int ans = 1;
        int n = rowIndex + 1;
        nthrow.push_back(ans);
        for(int c = 1 ; c < n ; c++){
            ans = ans*(n-c);
            ans = ans/(c);
            nthrow.push_back(ans);
        }
        return nthrow;
    }

};

int main(){
    Solution s1;
    int rowIndex = 3;

    for(int val : s1.getRow(rowIndex)){
        cout<<val<<" ";
    }
    return 0;
}