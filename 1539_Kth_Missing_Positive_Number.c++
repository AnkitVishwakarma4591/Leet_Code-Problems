# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int st = 0 , end = n-1;
        while(st <= end){
            int mid = st + (end-st)/2;
            int missing = arr[mid] -(mid+1);
            if(missing < k){
                st = mid +1;
            }else{
                end = mid-1;
            }
        }
        return k + end + 1;
    }
};

int main(){
    Solution s1;
    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    cout<<s1.findKthPositive(arr,k)<<endl;
    return 0;
}