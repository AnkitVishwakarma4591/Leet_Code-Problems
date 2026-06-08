# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int countless  = 0;
        int countequal = 0;

        for(int &num : nums) {
            if(num < pivot)
                countless++;
            else if(num == pivot)
                countequal++;
        }

        int i = 0; //less than pivot
        int j = countless; //equal to pivot
        int k = countless + countequal; //more than pivot
        vector<int> result(n);

        for(int &num : nums) {
            if(num < pivot) {
                result[i] = num;
                i++;
            } else if(num == pivot) {
                result[j] = num;
                j++;
            } else {
                result[k] = num;
                k++;
            }
        }
        
        return result;

    }
};


int main(){
    Solution s1;
    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;

    for(int val : s1.pivotArray(nums, pivot)){
        cout<<val<<" ";
    }
    return 0;
}