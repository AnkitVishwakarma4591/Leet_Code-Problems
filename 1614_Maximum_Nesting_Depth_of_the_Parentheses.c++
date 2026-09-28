# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int ans = 0;
        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                cnt++;
            }else if(s[i] == ')'){
                ans = max(cnt, ans);
                cnt--;
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};

int main(){
    Solution s1;
    string s = "(1)+((2))+(((3)))";

    cout<<s1.maxDepth(s)<<endl;
    
    return 0;
}