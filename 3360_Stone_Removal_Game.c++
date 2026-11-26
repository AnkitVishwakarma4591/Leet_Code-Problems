# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10) return false;

        int stonesToRemove = 10;
        bool aliceTurn = true;

        while(n >= stonesToRemove){
            n -= stonesToRemove;
            stonesToRemove--;
            aliceTurn = !aliceTurn;
        }

        return !aliceTurn;
    }
};

int main(){
    Solution s1;
    int n = 12;
    
    cout<<s1.canAliceWin(n)<<endl;

    return 0;
}