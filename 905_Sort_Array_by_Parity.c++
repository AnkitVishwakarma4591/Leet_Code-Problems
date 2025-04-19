# include <bits/stdc++.h>
using namespace std;


// Two Pointer approach
vector<int> twoPointerSortArrayByParity(vector<int>& nums){
    int st = 0 , end = nums.size() -1;

    while(st < end){
        if(nums[st] % 2 > nums[end] % 2){
            swap(nums[st],nums[end]);
        }

        if(nums[st] % 2 == 0) st++;
        if(nums[end] % 2 == 1) end--;
    }

    return nums;
}


vector<int> sortArrayByParity(vector<int>& nums){ //O(n)
    
    vector<int> even;
    vector<int> odd;

    for(int i=0 ; i<nums.size() ; i++){
        if(nums[i] % 2 == 0){
            even.push_back(nums[i]);
        }else{
            odd.push_back(nums[i]);
        }
    }

    // even fill
    for(int i = 0 ; i < even.size() ; i++){
        nums[i] = even[i];
    }

    // odd fill
    int j = 0;
    for(int i = even.size() ; i < nums.size() ; i++){
        nums[i] = odd[j];
        j++;
    }

    return nums;

}

int main(){
    vector<int> nums1 = {3,1,2,4};
    vector<int> nums2 = {0};

    for(int val : sortArrayByParity(nums1)){
        cout<<val<<" ";
    }
    cout<<endl;
    for(int val : sortArrayByParity(nums2)){
        cout<<val<<" ";
    }
    cout<<endl;

    for(int val : twoPointerSortArrayByParity(nums1)){
        cout<<val<<" ";
    }

    return 0;
}