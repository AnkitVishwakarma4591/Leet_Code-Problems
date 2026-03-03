# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findKthBit(int n, int k) {
        
        if(n == 1) return '0';

        int mid = 1 << (n - 1);

        if(k == mid) return '1';

        if(k < mid) {
            return findKthBit(n - 1, k);
        }

        char ch = findKthBit(n - 1, mid - (k - mid));
        return (ch == '0') ? '1' : '0';
    }
};

int main(){
    Solution s1;
    int n = 3, k = 1;

    cout<<s1.findKthBit(n, k)<<endl;
    
    return 0;
}