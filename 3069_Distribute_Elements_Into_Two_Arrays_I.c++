# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i = 2 ; i < nums.size() ; i++){
            if(arr1.back() > arr2.back()){
                arr1.push_back(nums[i]);
            }else{
                arr2.push_back(nums[i]);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {2,1,3};

    for(int val : s1.resultArray(nums)){
        cout<<val<<" ";
    }
    return 0;
}