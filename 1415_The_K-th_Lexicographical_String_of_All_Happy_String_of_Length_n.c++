# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string result;
    int k;

    void solve(int n, char prev, string &str) {

        if(n == 0) {
            k--;

            if(k == 0) result = str;
            return;
        }

        if(k < 0) return;

        for(char ch = 'a'; ch <= 'c'; ch++) {
            if(prev == ch) continue;

            str.push_back(ch);
            solve(n - 1, ch, str);
            str.pop_back();
        }
    }

    string getHappyString(int n, int k) {

        int total = 3 * pow(2, n - 1);
        result = "";

        if(total < k) return result;

        this->k = k;

        string str = "";
        solve(n, '0', str);

        return result;
    }
};

int main(){
    Solution s1;
    int n = 1, k = 3;

    cout<<s1.getHappyString(n, k)<<endl;
    
    return 0;
}