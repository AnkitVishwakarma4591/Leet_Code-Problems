# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long GCD(int a, int b){
        if(b == 0) return a;

        return GCD(b, a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(), Max = -1;
        vector<long long> prefixGcd(n);

        for(int i = 0 ; i < n ; i++){
            Max = max(nums[i], Max);
            prefixGcd[i] = GCD(nums[i], Max);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0, j = n-1;
        long long ans = 0;
        while(i < j){
            ans += GCD(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {2,6,4};

    cout<<s1.gcdSum(nums)<<endl;
    
    return 0;
}