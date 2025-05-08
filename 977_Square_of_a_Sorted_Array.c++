# include <iostream>
# include <bits/stdc++.h>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
        int val = pow(nums[i],2);
        ans.push_back(val);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> num = {-4,-1,0,3,10};
    
    for( int val : sortedSquares(num)){
        cout<<val<<" ";
    }

    return 0;
}