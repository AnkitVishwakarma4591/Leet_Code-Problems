# include <bits/stdc++.h>
# include <numeric>
using namespace std;

class Solution {
public:

    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        int gcdLength = std::__gcd(str1.size(), str2.size());

        return str1.substr(0, gcdLength);
    }
};

int main(){
    Solution s1;
    string str1 = "ABCABC";
    string str2 = "ABC";

    cout << s1.gcdOfStrings(str1, str2) << endl;

    return 0;
}