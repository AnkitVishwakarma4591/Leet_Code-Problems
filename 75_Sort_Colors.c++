# include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums){

    sort(nums.begin(),nums.end());

    for(int val : nums){
        cout<<val<<" ";
    }
}

int main(){
    vector<int> nums1 = {2,0,2,1,1,0};
    vector<int> nums2 = {2,0,1};

    sortColors(nums1);
    cout<<endl;
    sortColors(nums2);

    return 0;
}