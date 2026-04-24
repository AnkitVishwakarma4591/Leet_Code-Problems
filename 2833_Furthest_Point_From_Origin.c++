# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0;
        int right = 0;
        int dash = 0;

        for(char &ch : moves){
            if(ch == 'R') right++;
            else if(ch == 'L') left++;
            else dash++;
        }

        return abs(left-right) + dash;
    }
};

int main(){
    Solution s1;
    string moves = "L_RL__R";

    cout<<s1.furthestDistanceFromOrigin(moves)<<endl;
    
    return 0;
}