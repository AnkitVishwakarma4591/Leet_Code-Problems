# include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    int findGcd(int l, int s){
        if(s == 0) return l;
        while(l % s != 0){
            int temp = l % s;
            l = s;
            s = temp;
        }
        return s;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for(auto val : deck){
            m[val]++;
        } 
        int gcdVal = 0;
        for(auto val : m){
            gcdVal = findGcd(gcdVal, val.second);
        }
        return gcdVal >= 2;
    }
};

int main(){
    Solution s1;
    vector<int> deck = {1,2,3,4,4,3,2,1};

    cout<<s1.hasGroupsSizeX(deck)<<endl;

    return 0;
}