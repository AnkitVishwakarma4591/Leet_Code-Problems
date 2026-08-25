# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int temp = k;

        while(find(nums.begin(), nums.end(), k) != nums.end()){
            k += temp;
        }
        return k;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {8,2,3,4,6};
    int k = 2;

    cout<<s1.missingMultiple(nums, k)<<endl;
    
    return 0;
}

