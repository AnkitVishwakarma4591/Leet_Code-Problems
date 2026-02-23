# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n-k+1 < pow(2,k)) return false;

        set<string> temp;
        int st = 0, end = k-1;
        while(end < n){
            temp.insert(s.substr(st, k));
            st++;
            end++;
        }
        return temp.size() == pow(2,k);
    }
};

int main(){
    Solution s1;
    string s = "00110110";
    int k = 2;

    cout<<s1.hasAllCodes(s, k)<<endl;
    
    return 0;
}