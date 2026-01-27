# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(int i = 0 ; i < arr1.size() ; i++){
            bool isGreater = true;
            for(int j = 0 ; j < arr2.size() ; j++){
                if(abs(arr1[i] - arr2[j]) <= d){
                    isGreater = false;
                    break;
                }
            }
            if(isGreater){
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;
    vector<int> arr1 = {4,5,8};
    vector<int> arr2 = {10,9,1,8};

    int d = 2;

    cout<<s1.findTheDistanceValue(arr1, arr2, d)<<endl;

    return 0;
}