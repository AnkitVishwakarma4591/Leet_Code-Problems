# include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = i+1 ; j < nums.size() ; j++){
                if(nums[i] == nums[j]){
                    if(abs(i-j) <= k) return true;
                }
            }
        }
        return false;
    }
};

//this sol will give TLE
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastSeen;
        for (int i = 0; i < nums.size(); i++) {
            if (lastSeen.count(nums[i]) && i - lastSeen[nums[i]] <= k)
                return true;
            lastSeen[nums[i]] = i;
        }
        return false;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,2,3,1};
    int k = 3;

    cout<<s1.containsNearbyDuplicate(nums, k)<<endl;
    
    return 0;
}


