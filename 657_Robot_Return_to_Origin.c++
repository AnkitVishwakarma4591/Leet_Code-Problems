# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int U = 0, L = 0;
        for(int i = 0 ; i < moves.size() ; i++){
            if(moves[i] == 'U'){
                U++;
            }
            else if(moves[i] == 'D'){
                U--;
            }
            else if(moves[i] == 'L'){
                L++;
            }
            else if(moves[i] == 'R'){
                L--;
            }
        }
        return (U == 0 && L == 0);
    }
};

int main(){
    Solution s1;
    string moves = "UDLR";
    cout<<s1.judgeCircle(moves)<<endl;
    
    return 0;
}