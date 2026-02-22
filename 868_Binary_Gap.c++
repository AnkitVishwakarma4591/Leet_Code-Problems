# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string binary_form(int n){
        string s = "";
        while(n > 0){
            s = char((n % 2) + '0') + s;
            n /= 2;
        }
        return s;
    }

    int count_distance(int n){
        string s = binary_form(n);
        int cnt_dis = 0;
        int prev = -1;

        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '1'){
                if(prev != -1){
                    cnt_dis = max(cnt_dis, i - prev);
                }
                prev = i;
            }
        }
        return cnt_dis;
    }

    int binaryGap(int n) {
        return count_distance(n);
    }
};

int main(){
    Solution s1;
    int n = 22;

    cout<<s1.binaryGap(n)<<endl;
    
    return 0;
}