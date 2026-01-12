# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int k = flowerbed.size();
        int cnt = 0;

        for (int i = 0; i < k; i++) {
            // check left
            int left = (i == 0) ? 0 : flowerbed[i - 1];
            // check right
            int right = (i == k - 1) ? 0 : flowerbed[i + 1];

            if (flowerbed[i] == 0 && left == 0 && right == 0) {
                cnt++;
                flowerbed[i] = 1;   // plant immediately
            }
        }

        return cnt >= n;
    }
};

int main(){
    Solution s1;
    vector<int> flowerbed = {1,0,0,0,1};
    int n = 1;

    cout<<s1.canPlaceFlowers(flowerbed, n)<<endl;
    
    return 0;
}
