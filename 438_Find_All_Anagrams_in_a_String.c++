# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.size() > s.size()) return ans;

        vector<int> freqP(26, 0), freqS(26, 0);

        for (int i = 0; i < p.size(); i++) {
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }

        if (freqP == freqS) ans.push_back(0);

        for (int i = p.size(); i < s.size(); i++) {
            freqS[s[i] - 'a']++;                 // add new char
            freqS[s[i - p.size()] - 'a']--;      // remove old char

            if (freqP == freqS)
                ans.push_back(i - p.size() + 1);
        }

        return ans;
    }
};


// Brute force
// class Solution {
// public:
//     bool isAnagrams(string s, string sub_s){
//         if(s.size() != sub_s.size()) return false;
//         unordered_map<char, int> m1, m2;

//         for(auto val : s){
//             m1[val]++;
//         }
//         for(auto val : sub_s){
//             m2[val]++;
//         }

//         if(m1 != m2)  return false;

//         return true;
//     }
//     vector<int> findAnagrams(string s, string p) {
//         int s_size = s.size();
//         int p_size = p.size();

//         if (p_size > s_size) return {};

//         vector<int> ans;

//         int left = 0, right = p_size;

//         string s_copy = "";
//         for(int i = 0 ; i < p_size ; i++){
//             s_copy += s[i];
//         }

//         while(right <= s_size){
//             if(isAnagrams(p, s_copy)){
//                 ans.push_back(left);
//             }
//             if (right < s_size) {
//                 s_copy += s[right];
//                 s_copy.erase(0, 1);
//             }
//             left++;
//             right++;
//         }
//         return ans;
//     }
// };

int main(){
    Solution s1;
    string s = "cbaebabacd", p = "abc";

    for(int val : s1.findAnagrams(s, p)){
        cout<<val<<" ";
    }
    return 0;
}