# include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums){
    int n = nums.size();

    vector<int> ans;
    int sum = 0;

    for(int i=0 ; i<n ; i++){
        sum += nums[i];
        ans.push_back(sum);
    }

    return ans;
}

void printArray(vector<int> &nums){
    for(int val : runningSum(nums)){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> nums1 = {1,2,3,4};
    vector<int> nums2 = {1,1,1,1,1};
    vector<int> nums3 = {3,1,2,10,1};

    printArray(nums1);
    printArray(nums2);
    printArray(nums3);
    
    return 0;
}