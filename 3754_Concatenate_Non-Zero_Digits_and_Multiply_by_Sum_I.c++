# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    long long sumAndMultiply(int n) {
        string num = to_string(n);
        ll result = 0;
        ll Sum = 0;
        for(int i = 0 ; i < num.size() ; i++){
            if(num[i] != '0'){
                result += num[i] - '0';
                Sum += num[i] - '0';
                result *= 10;
            }
        }
        return Sum * result/10;
    }
};

int main(){
    Solution s1;
    int n = 10203004;
    cout<<s1.sumAndMultiply(n)<<endl;
    
    return 0;
}