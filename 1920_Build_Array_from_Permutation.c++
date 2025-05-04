# include <bits/stdc++.h>
using namespace std;

vector<int> buildArray(vector<int>& nums) {

    int n = nums.size();
    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
        ans.push_back(nums[nums[i]]);
    }
    return ans;  
}

int main(){
    vector<int> nums = {0,2,1,5,3,4};

    for(int val : buildArray(nums)){
        cout<<val<<" ";
    }

    return 0;
}