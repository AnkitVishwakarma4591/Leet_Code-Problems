# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int totalA = 0;
        for(auto ch : s){
            if(ch == 'a') totalA++;
        }

        if(totalA == 0 || totalA == n) return 0;

        int prefA = 0, prefB = 0;
        int ans = totalA;

        for(auto ch : s){
            if(ch == 'b') prefB++;
            else prefA++;

            ans = min(ans, prefB + (totalA - prefA));
        }
        return min(ans, prefB);
    }
};

int main(){
    Solution s1;

    string s = "aababbab";

    cout<<s1.minimumDeletions(s)<<endl;
    
    return 0;
}