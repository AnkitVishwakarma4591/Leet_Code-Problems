# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {

        //brute force approach
        /*
        map<int, int> m;
        for(int val : arr){
            m[val]++;
        }

        int lucky = -1;
        for(auto &m1 : m){
            if(m1.first == m1.second){
                lucky = m1.first;
            };
        }
        return lucky;
        */

        // optimal approach
        unordered_map<int, int> m;
        for(int val : arr){
            m[val]++;
        }

        int lucky = -1;
        for(auto &m1 : m){
            if(m1.first == m1.second){
                lucky = max(lucky,m1.first);
            };
        }
        return lucky;
    }
};

int main(){
    Solution s1;
    vector<int> arr = {1,2,2,3,3,3};

    cout<<s1.findLucky(arr)<<endl;

    return 0;
}