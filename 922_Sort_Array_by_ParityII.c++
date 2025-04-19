# include <bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParityII(vector<int>& nums){

    // Test case will pass but not accepted
    // for(int i = 0 ; i < nums.size() ; i++){
    //     if(i % 2 > nums[i] % 2){
    //         swap(nums[i],nums[i+1]);
    //     }
    // }
    // return nums;


    // All test cases pass and accepted
    int evenidx = 0;
    int oddidx = 1;
    int n = nums.size();

    while(evenidx < n && oddidx < n){
        if(evenidx % 2 == 0){
            evenidx +=2;
        }else if(oddidx % 2 == 1){
            oddidx += 2;
        }else{
            swap(nums[evenidx],nums[oddidx]);
        }
    }
    return nums;
}


int main(){
    vector<int> nums1 = {4,2,5,7};
    vector<int> nums2 = {2,3};

    for(int val : sortArrayByParityII(nums1)){
        cout<<val<<" ";
    }
    cout<<endl;
    for(int val : sortArrayByParityII(nums2)){
        cout<<val<<" ";
    }


    return 0;
}