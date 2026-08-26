# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int cnt = 0, j = 0;
        for(int i = 0 ; i < n  ; i++){
            if(s[i] == '1'){
                cnt++;
            }
            while(cnt == k){
                string curr_sub = s.substr(j, i-j+1);

                if(ans == "" || curr_sub.size() < ans.size() || (curr_sub.size() == ans.size() && curr_sub < ans)){
                    ans = curr_sub;
                }

                if(s[j] == '1'){
                    cnt--;
                }
                j++;
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;
    string s = "100011001";
    int k = 3;
    
    cout<<s1.shortestBeautifulSubstring(s, k)<<endl;

    return 0;
}