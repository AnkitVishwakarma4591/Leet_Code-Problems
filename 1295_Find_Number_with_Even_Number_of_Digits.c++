# include <bits/stdc++.h>
using namespace std;

int findNumber(vector<int> &nums){

    int evencount = 0;

    for(int i=0 ; i<nums.size() ; i++){
        int count = 0;
        if(nums[i] == 0){
            count = 1;
        }else{
            while(nums[i] > 0){
                nums[i] = nums[i]/10;
                count++;
            }
        }

        if(count % 2 == 0){
            evencount++;
        }
    }
    return evencount;
}

int main(){
    vector<int> nums1 = {12,345,2,6,7896};
    vector<int> nums2 = {555,901,482,1771};

    cout<<findNumber(nums1)<<endl;
    cout<<findNumber(nums2)<<endl;

    return 0;
}