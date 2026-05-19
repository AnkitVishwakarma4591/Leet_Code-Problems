# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> small;
        vector<int> big;

        if(m >= n){
            small = nums2;
            big = nums1;
        }else{
            small = nums1;
            big = nums2;
        }

        for(int i = 0 ; i < small.size() ; i++){
            int target = small[i];

            int st = 0, end = big.size() - 1;

            while(st <= end){
                int mid = st + (end - st)/2;

                if(big[mid] == target) return target;

                if(target > big[mid]){
                    st = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution s1;
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4};

    cout<<s1.getCommon(nums1, nums2)<<endl;
    
    return 0;
}