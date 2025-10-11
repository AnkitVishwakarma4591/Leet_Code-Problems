# include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> freq;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == key) {
                freq[nums[i + 1]]++;
            }
        }

        int ans = -1, maxCount = 0;
        for (auto& pair : freq) {
            if (pair.second > maxCount) {
                maxCount = pair.second;
                ans = pair.first;
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,100,200,1,100};
    int k = 1;
    cout<<s1.mostFrequent(nums, k)<<endl;

    return 0;
}