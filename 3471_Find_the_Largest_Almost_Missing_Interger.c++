# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> vec2d;

        vector<int> temp;
        for(int i = 0 ; i < k ; i++){
            temp.push_back(nums[i]);
        }

        vec2d.push_back(temp);

        for(int i = k ; i < n ; i++){
            temp.push_back(nums[i]);
            temp.erase(temp.begin());
            vec2d.push_back(temp);
        }

        int ans = -1;
        for(int val : nums){
            int cnt = 0;
            for(auto &num : vec2d){
                if(find(num.begin(), num.end(), val) != num.end()){
                    cnt++;
                }
            }

            if(cnt == 1 && val > ans){
                ans = val;
            }
        }

        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {3,9,2,1,7};
    int k = 3;

    cout<<s1.largestInteger(nums, k)<<endl;

    return 0;
}