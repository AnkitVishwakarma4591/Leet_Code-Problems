# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string numbers = "123456789";
        vector<int> result;
        
        int low_len = log10(low)+1;
        int high_len = log10(high)+1;

        for(int len = low_len; len <= high_len; ++len){
            for(int st = 0 ; st <= 9-len; ++st){
                string sub = numbers.substr(st, len);
                int num = stoi(sub);

                if(num >= low && num <= high){
                    result.push_back(num);
                }
            }
        }
        return result;
    }
};

int main(){
    Solution s1;
    int low = 1000, high = 13000;

    for(int val : s1.sequentialDigits(low, high)){
        cout<<val<<" ";
    }
    return 0;
}