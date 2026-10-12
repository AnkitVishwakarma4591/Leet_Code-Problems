# include <bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n+1, 0);
        for(int i = 0 ; i < n ; i++){
            prefixSum[i+1] = nums[i] + prefixSum[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right+1] - prefixSum[left];
    }
};

int main(){
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray s1(nums);

    cout<<s1.sumRange(2, 5)<<endl;
    
    return 0;
}