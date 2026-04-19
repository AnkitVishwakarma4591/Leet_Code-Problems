# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(); 
        int n = nums2.size(); 

        int i = 0, j = 0;

        int result = 0;

        while(i < m &&  j < n){
            if(nums1[i] > nums2[j]){
                i++;
            }else{
                result = max(result, j-i);
                j++;
            }
        }
        return result;
    }
};

int main(){
    Solution s1;
    vector<int> nums1 = {55,30,5,4,2}, nums2 = {100,20,10,10,5};

    cout<<s1.maxDistance(nums1, nums2)<<endl;
    
    return 0;
}