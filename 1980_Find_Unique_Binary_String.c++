# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = "";

        for(int i = 0 ; i < n ; i++) {
            result += (nums[i][i] == '1') ? '0' : '1';
        }
        
        return result;        
    }
};

int main(){
    Solution s1;
    vector<string> nums = {"01","10"};

    cout<<s1.findDifferentBinaryString(nums)<<endl;
    
    return 0;
}