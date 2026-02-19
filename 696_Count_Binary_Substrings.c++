# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int result = 0;
        int prev_count = 0;
        int curr_count = 1;

        for(int i = 1 ; i < n ; i++){
            if(s[i] == s[i-1]){
                curr_count++;
            }else{
                result += min(prev_count, curr_count);
                prev_count = curr_count;
                curr_count = 1;
            }
            
        }
        return result + min(prev_count, curr_count);
    }
};

int main(){
    Solution s1;
    string s = "00110011";

    cout<<s1.countBinarySubstrings(s)<<endl;
    
    return 0;
}