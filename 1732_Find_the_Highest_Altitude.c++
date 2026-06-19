# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int n = gain.size();

        vector<int> temp(n+1);
        temp[0] = 0;
        int ans = 0;

        for(int i = 1 ; i <= n ; i++){
            temp[i] = temp[i-1] - gain[i-1];

            if(-temp[i] > ans){
                ans = abs(temp[i]);
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> gain = {-5,1,5,0,-7};

    cout<<s1.largestAltitude(gain)<<endl;
    
    return 0;
}