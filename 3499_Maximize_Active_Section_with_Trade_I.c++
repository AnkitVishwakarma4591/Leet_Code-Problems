# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        int activeCount = count(s.begin(), s.end(), '1');

        vector<int> inactiveBlocks;

        int i = 0;
        while(i < n){
            if(s[i] == '0'){
                int start = i;
                while(i < n && s[i] == '0') i++;

                inactiveBlocks.push_back(i-start);
            }else{
                i++;
            }
        }

        int maxPairSum = 0;
        for(int i = 1 ; i < inactiveBlocks.size() ; i++){
            int Sum = inactiveBlocks[i] + inactiveBlocks[i-1];
            if(Sum > maxPairSum){
                maxPairSum = Sum;
            }

        }
        return maxPairSum + activeCount;
    }
};

int main(){
    Solution s1;
    string s = "0100";

    cout<<s1.maxActiveSectionsAfterTrade(s)<<endl;
    return 0;
}