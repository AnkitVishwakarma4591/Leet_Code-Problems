# include <iostream>
using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        // int temp = n;
        int ans = 0;
        while(n > 1){
            int temp = n/2;
            ans += temp;
            n = n - temp;
        }
        return ans;
    }
};

int main(){
    Solution s1;
    int n = 7;

    cout<<s1.numberOfMatches(n)<<endl;

    return 0;
}