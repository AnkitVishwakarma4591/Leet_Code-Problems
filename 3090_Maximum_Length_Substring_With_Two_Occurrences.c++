# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {

        int n = s.size();

        unordered_map<char, int> m;
        
        int left = 0, ans = 0;

        for(int right = 0 ; right < n ; right++){
            m[s[right]]++;

            while(m[s[right]] > 2){
                m[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;

    }
};

int main(){
    Solution s1;
    string s = "bcbbbcba";

    cout<<s1.maximumLengthSubstring(s)<<endl;
    
    return 0;
}