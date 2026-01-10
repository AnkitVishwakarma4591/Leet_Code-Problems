# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {

        // optimize code
        unordered_set<int> s(candyType.begin(), candyType.end());
        return min((int)s.size(), (int)candyType.size() / 2);

        // Brute force
        // int n = candyType.size();

        // set<int> s;
        // for(int val : candyType){
        //     s.insert(val);
        // }

        // if(s.size() < n/2){
        //     return s.size();
        // }
        // return n/2;
    }
};

int main(){
    Solution s1;
    vector<int> candyType = {1,1,2,2,3,3};

    cout<<s1.distributeCandies(candyType)<<endl;
    
    return 0;
}