# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDigSum(string temp){
        int sum = 0;

        for(char val : temp){
            sum += val - '0';
        }
        return to_string(sum);
    }

    string digitSum(string s, int k) {
        while(s.size() > k){
            string ans = "";
            while(!s.empty()){
                string temp = s.substr(0, k);
                s.erase(0, k);
                ans += findDigSum(temp);
            }
            s = ans;
        }

        return s;
    }
};

int main(){
    Solution s1;
    string s = "11111222223";
    int k = 3;

    cout<<s1.digitSum(s, k)<<endl;

    return 0;
}