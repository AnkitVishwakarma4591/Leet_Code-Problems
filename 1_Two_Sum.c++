# include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums , int target){
    int n = nums.size();
    vector<int> temp;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(nums[i] + nums[j] == target){
                temp.push_back(i);
                temp.push_back(j);
            }
        }
    }
    return temp;

}

int main(){
    vector<int> nums1 = {2,7,11,15};
    int target1 = 9;

    vector<int> nums = {3,2,4};
    int target2 = 6;

    vector<int> nums = {3,3};
    int target3 = 6;

    for(int val : twoSum(nums,target1)){
        cout<<val<<" ";
    }

    for(int val : twoSum(nums,target2)){
        cout<<val<<" ";
    }

    for(int val : twoSum(nums,target3)){
        cout<<val<<" ";
    }

    return 0;
}