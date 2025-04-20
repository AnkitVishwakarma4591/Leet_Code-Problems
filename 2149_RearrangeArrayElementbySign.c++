# include <bits/stdc++.h>
using namespace std;


/*--------------------------------------------------------------------------
//Bruteforce approach.
----------------------------------------------------------------------------
vector<int> rearrangeArray(vector<int>& nums){

    int n = nums.size();
    vector<int> pos;
    vector<int> neg;

    for(int i = 0 ; i < n ; i++){
        if(nums[i] > 0){
            pos.push_back(nums[i]);
        }else{
            neg.push_back(nums[i]);
        }
    }

    for(int i = 0 ; i < n/2 ; i++){
        nums[2*i] = pos[i];
        nums[2*i+1] = neg[i];
    }
    return nums;
}
---------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------
vector<int> rearrangeArray(vector<int>& nums){

    int n = nums.size();
    vector<int> pos;
    vector<int> neg;

    for(int i = 0 ; i < n ; i++){
        if(nums[i] > 0){
            pos.push_back(nums[i]);
        }else{
            neg.push_back(nums[i]);
        }
    }
    if(pos.size() > neg.size()){
        for(int i = 0 ; i < neg.size() ; i++){
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }
        int index = neg.size() * 2;
        for(int i = neg.size() ; i < pos.size() ; i++){
            nums[index] = pos[i];
            index++;
        }
    }
    else{
        for(int i = 0 ; i < pos.size() ; i++){
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }
        int index = pos.size() * 2;
        for(int i = pos.size() ; i < neg.size() ; i++){
            nums[index] = neg[i];
            index++;
        }
    }

    return nums;
}
----------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------
// Optimal Solution O(n)
----------------------------------------------------------------------------------*/
vector<int> rearrangeArray(vector<int>& nums){

    int n = nums.size();
    vector<int> ans(n,0);
    int evenidx = 0;
    int oddidx = 1;

    for(int i = 0 ; i < n ; i++){
        if(nums[i] > 0){
            ans[evenidx] = nums[i];
            evenidx += 2;
        }else{
            ans[oddidx] = nums[i];
            oddidx += 2;
        }
    }

    return ans;
}

int main(){

    vector<int> nums1 = {3,1,-2,-5,2,-4};
    vector<int> nums2 = {-1,1};

    for(int val : rearrangeArray(nums1)){
        cout<<val<<" ";
    }
    cout<<endl;
    for(int val : rearrangeArray(nums2)){
        cout<<val<<" ";
    }

    return 0;
}