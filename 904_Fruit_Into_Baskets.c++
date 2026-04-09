# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0;
        int maxlen = 0;

        unordered_map<int, int> freq;

        while (r < n) {
            freq[fruits[r]]++;

            while (freq.size() > 2) {
                freq[fruits[l]]--;
                if (freq[fruits[l]] == 0) {
                    freq.erase(fruits[l]);
                }
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};

int main(){
    Solution s1;

    vector<int> fruits = {1,2,3,2,2};

    cout<<s1.totalFruit(fruits)<<endl;

    return 0;
}