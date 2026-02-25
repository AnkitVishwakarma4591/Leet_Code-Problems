# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> p;

        for(int val : arr){
            int count = 0;
            int n = val;
            while(n > 0){
                n = n & (n-1);
                count++;
            }
            p.push_back({count, val});
        }
        sort(p.begin(), p.end());

        vector<int> ans;
        for(auto val : p){
            ans.push_back(val.second);
        }
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> arr = {0,1,2,3,4,5,6,7,8};

    for(int val : s1.sortByBits(arr)){
        cout<<val<<" ";
    }
    
    return 0;
}