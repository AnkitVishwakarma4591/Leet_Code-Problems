# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    bool dfs(vector<int> &arr, int i){
        if(i < 0 || i >= n || arr[i] < 0){
            return false;
        }
        if(arr[i] == 0){
            return true;
        }

        arr[i] *= -1;

        int left = dfs(arr, i - arr[i]);
        int right = dfs(arr, i + arr[i]);

        return left || right;
    } 
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();

        return dfs(arr, start);
    
    }
};

int main(){
    Solution s1;
    vector<int> arr = {4,2,3,0,3,1,2};
    int start = 5;

    cout<<s1.canReach(arr, start)<<endl;
    
    return 0;
}