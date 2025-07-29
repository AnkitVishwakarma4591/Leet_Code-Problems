# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {

        int idx = -1;
        for(int i = 0 ; i < num.size() ; i++){
            int n = num[i] - '0';
            if(n%2 != 0){
                idx = i;
            }
        }
        if(idx == -1){
            return "";
        }else{
            return num.substr(0, idx + 1);
        }
    }
};

int main(){
    Solution s1;
    string num1 = "52";
    string num2 = "4206";
    string num3 = "35427";

    for(auto val : s1.largestOddNumber(num3)){
        cout<<val;
    }
    return 0;
}