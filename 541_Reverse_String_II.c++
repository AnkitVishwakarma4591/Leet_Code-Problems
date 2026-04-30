# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        
        for (int i = 0; i < n; i += 2 * k) {
            
            int left = i;
            int right = min(i + k - 1, n - 1);
            
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};

int main(){
    Solution s1;
    string s = "abcdefg";
    int k = 2;

    cout<<s1.reverseStr(s, k)<<endl;
    
    return 0;
}