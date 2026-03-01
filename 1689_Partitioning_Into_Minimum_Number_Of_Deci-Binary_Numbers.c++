# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;

        for(char ch : n) {
            int num = ch - '0';
            ans = max(ans, num);
        }

        return ans;
    }
};

int main(){
    Solution s1;

    string n = "32";
    cout<<s1.minPartitions(n)<<endl;
    
    return 0;    
}