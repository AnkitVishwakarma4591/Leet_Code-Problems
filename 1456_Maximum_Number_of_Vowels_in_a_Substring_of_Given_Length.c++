# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int result = 0;
        string ans = "";
        for(int i = 0 ; i < k ; i++){
            ans += s[i];
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                result++;
            }
        }
        int total = result;
        for(int i = k ; i < n ; i++){
            ans += s[i];
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                result++;
            }
            if(ans[0] == 'a' || ans[0] == 'e' || ans[0] == 'i' || ans[0] == 'o' || ans[0] == 'u'){
                result--;
                ans.erase(0,1);
            }else{
                ans.erase(0,1);
            }
            total = max(total, result);
        }  
        return total; 
    }
};

int main(){
    Solution s1;
    string s = "abciiidef";
    int k = 3;

    cout<<s1.maxVowels(s, k)<<endl;

    return 0;
}