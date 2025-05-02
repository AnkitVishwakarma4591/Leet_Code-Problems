# include <bits/stdc++.h>
using namespace std;

vector<int> shuffle(vector<int> &nums, int n){

    vector<int> ans;

    for(int i=0 ; i<nums.size()/2 ; i++){
        ans.push_back(nums[i]);
        ans.push_back(nums[n+i]);
    }

    return ans;
}

int main(){
    vector<int> nums = {2,5,1,3,4,7};
    int n = 3;

    for(int val : shuffle(nums,n)){
        cout<<val<<" ";
    }

    return 0;
}