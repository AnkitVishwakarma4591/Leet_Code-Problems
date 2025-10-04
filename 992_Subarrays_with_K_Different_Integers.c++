# include <bits\stdc++.h>
using namespace std;

/*
// Brute force approach
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            map<int, int> m;
            for(int j = i ; j < n ; j++){
                m[nums[j]]++;
                if(m.size() == k){
                    cnt++;
                }else if(m.size() > k){
                    break;
                }
            }
        }
        return cnt;
    }
};
*/

class Solution {
public:
    int totalSubarrays(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> m;

        while(r < n){
            m[nums[r]]++;
            while(m.size() > k){
                m[nums[l]]--;
                if(m[nums[l]] == 0){
                    m.erase(nums[l]);
                }
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return totalSubarrays(nums, k) - totalSubarrays(nums, k-1);
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,1,2,3};
    int k = 2;

    cout<<s1.subarraysWithKDistinct(nums, k)<<endl;

    return 0;
}