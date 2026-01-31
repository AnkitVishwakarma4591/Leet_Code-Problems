# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        // sort(arr.begin(), arr.end());

        // vector<vector<int>> ans;
        // int n = arr.size();
        // int mindiff = INT_MAX;
        // int i = 0, j = 1;
        // while(i <= n -2 && j <= n-1){
        //     int MIN = abs(arr[i] - arr[j]);
        //     mindiff = min(mindiff, MIN);
        //     i++;
        //     j++;
        // }
        // i = 0, j = 1;
        // while(i <= n -2 && j <= n-1){
        //     if(abs(arr[i] - arr[j]) == mindiff){
        //         ans.push_back({arr[i], arr[j]});
        //     }
        //     i++;
        //     j++;
        // }
        // return ans;

        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        int n = arr.size();
        int mindiff = INT_MAX;

        for(int i = 0; i < n - 1; i++){
            mindiff = min(mindiff, arr[i+1] - arr[i]);
        }

        for(int i = 0; i < n - 1; i++){
            if(arr[i+1] - arr[i] == mindiff){
                ans.push_back({arr[i], arr[i+1]});
            }
        }

        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> arr = {4,2,1,3};

    for(auto vec : s1.minimumAbsDifference(arr)){
        for(int val : vec){
            cout<<val<<" ";
        }
    }

    return 0;
}