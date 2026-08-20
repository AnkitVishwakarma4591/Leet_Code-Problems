# include <bits/stdc++.h>
using namespace std;

set<vector<int>> s;
void getAllCombinations(vector<int> &arr, int idx, int tar, vector<vector<int>> &ans, vector<int> &combin){
    if(idx == arr.size() || tar < 0){
        return;
    }

    if(tar == 0){
        if(s.find(combin) == s.end()){
            ans.push_back(combin);
            s.insert(combin);
        }
        return;
    }

    combin.push_back(arr[idx]);
    // single
    getAllCombinations(arr, idx+1, tar-arr[idx], ans, combin);

    // multiple
    getAllCombinations(arr, idx, tar-arr[idx], ans, combin);
    combin.pop_back();

    // exclusion
    getAllCombinations(arr, idx+1, tar, ans, combin);
}

vector<vector<int>> CombinationSum(vector<int> &arr, int target){
    vector<vector<int>> ans;
    vector<int> combin;

    getAllCombinations(arr, 0, target, ans, combin);
}

int main(){
    vector<int>  arr = {2,3,6,7};
    int target = 7;


    CombinationSum(arr,target);
    // for(auto val : CombinationSum(arr,target)){
    //     for(auto val1 : val){
    //         cout<<val1<<" ";
    //     }
    // }
    return 0;
}