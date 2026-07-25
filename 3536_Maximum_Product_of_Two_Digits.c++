# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        vector<int> nums;
        while(n > 0){
            nums.push_back(n % 10);
            n /= 10;
        }
        int p = nums.size();
        sort(nums.begin(), nums.end());

        return nums[p-1] * nums[p-2];
    }
};

int main(){
    Solution s1;
    int n = 31;
    cout<<s1.maxProduct(n)<<endl;
    
    return 0;
}