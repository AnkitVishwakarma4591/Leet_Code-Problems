# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();

        int MinDis = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            if(words[i] == target){
                int straightDis = abs(i - startIndex);
                int circularDis = (n - straightDis);

                MinDis = min(MinDis, min(straightDis, circularDis));                
            }
        }

        return MinDis == INT_MAX ? -1 : MinDis;
    }
};

int main(){
    Solution s1;
    vector<string> words = {"hello","i","am","leetcode","hello"};
    string target = "hello";
    int startIndex = 1;

    cout<<s1.closestTarget(words, target, startIndex)<<endl;
    
    return 0;
}