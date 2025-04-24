# include <bits/stdc++.h>
using namespace std;

vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans(2*n);
    // for(int i=0 ; i<n ; i++){
    //     ans.push_back(nums[i]);
    // }
    // for(int i=0 ; i<n ; i++){
    //     ans.push_back(nums[i]);
    // }

    for(int i=0;i<n;i++){
        ans[i] = nums[i];
        ans[i+n] = nums[i];
    }
    return ans;        
}

void printArray(vector<int> &nums){
    for(int val : getConcatenation(nums)){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> nums1 = {1,2,1};
    vector<int> nums2 = {1,3,2,1};

    printArray(nums1);
    printArray(nums2);

    return 0;
    
}