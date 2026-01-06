# include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isPerfectSquare(int num){
        long long st = 0, end = 0;

        while(st <= end){
            long long mid = st + (end - st)/2;
            long long sq = mid * mid;

            if(sq == num) return true;
            else if(sq < num) st = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};

int main(){
    Solution s1;
    int num = 512;

    cout<<s1.isPerfectSquare(num)<<endl;

    return 0;
}