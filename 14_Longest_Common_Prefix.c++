# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.empty()) return "";
        
        sort(strs.begin(), strs.end());

        int n = strs.size();
        string first = strs[0];
        string last = strs[n-1];
        string ans = "";
        for(int i = 0 ; i < min(first.size(), last.size()) ; i++){
            if(first[i] == last[i]){
                ans += first[i];
            }else{
                break;
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;
    vector<string> strs = {"flower","flow","flight"};

    cout<<s1.longestCommonPrefix(strs)<<endl;

    return 0;
}