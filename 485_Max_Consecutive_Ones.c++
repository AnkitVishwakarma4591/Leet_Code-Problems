# include <iostream>
# include <vector>
# include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums){

    int n = nums.size();
    int current = 0;
    int max_con = 0;

    for(int i=0;i<n;i++){
        if(nums[i] == 1){
            current++;
            max_con = max(max_con,current);
        }else{
            current = 0;
        }
    }

    return max_con;

}

int main(){
    vector<int> nums1 = {1,1,0,1,1,1};
    vector<int> nums2 = {1,0,1,1,0,1};

    cout<<findMaxConsecutiveOnes(nums1)<<endl;
    cout<<findMaxConsecutiveOnes(nums2)<<endl;

    return 0;
}