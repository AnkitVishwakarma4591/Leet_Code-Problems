# include <bits\stdc++.h>
using namespace std;

/*
// wrost case/ brute force approach
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        
        for(int i = 0 ; i < n ; i++){
            vector<int> hash(3,0);
            for(int j = i ; j < n ; j++){
                hash[s[j] -'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3){
                    cnt++; 
                    // or we can write cnt = cnt + (n-j); break;
                    // it will optimize a little bit TC, but not full
                }
            }
        }
        return cnt;
    }
};
*/

// Optimal approach
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> last(3, -1);
        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            last[s[i] - 'a'] = i;
            if (last[0] != -1 && last[1] != -1 && last[2] != -1) {
                cnt += 1 + min({last[0], last[1], last[2]});
            }
        }
        return cnt;
    }
};

int main(){
    Solution s1;
    string s = "abcabc";

    cout<<s1.numberOfSubstrings(s)<<endl;
    return 0;
}
