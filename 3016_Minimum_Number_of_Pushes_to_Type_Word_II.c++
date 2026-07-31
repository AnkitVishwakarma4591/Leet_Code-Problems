# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        int totalPushes = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break; 

            int pushesPerChar = (i / 8) + 1; 
            totalPushes += freq[i] * pushesPerChar;
        }

        return totalPushes;
    }
};

int main(){
    Solution s1;
    string word = "aabbccddeeffgghhiiiiii";

    cout<<s1.minimumPushes(word)<<endl;
    
    return 0;
}