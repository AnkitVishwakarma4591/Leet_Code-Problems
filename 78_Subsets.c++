# include <bits/stdc++.h>
using namespace std;

void getAllSubSets(vector<int> &nums , vector<int> &ans, vector<vector<int>> &allSubsets, int i){
    if(i == nums.size()){
        allSubsets.push_back({ans});
        return;
    }

    // include
    ans.push_back(nums[i]);
    getAllSubSets(nums,ans,allSubsets,i+1);

    ans.pop_back();
    // exclude
    getAllSubSets(nums,ans,allSubsets,i+1);

}

vector<vector<int>> Subsets(vector<int> &nums){
    vector<vector<int>> allSubsets;
    vector<int> ans;

    getAllSubSets(nums,ans,allSubsets,0);

    return allSubsets;
}

int main(){
    vector<int> nums = {1,2,3};

    for(auto val : Subsets(nums)){
        for(auto val2 : val){
            cout<<val2<<" ";
        }
        cout<<endl;
    }

    return 0;
}
