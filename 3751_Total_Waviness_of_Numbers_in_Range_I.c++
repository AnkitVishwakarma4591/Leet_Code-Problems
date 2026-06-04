# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1 ; i <= num2 ; i++){
            deque<int> values;
            int temp = i;
            while(temp > 0){
                values.push_front(temp % 10);
                temp /= 10;
            }

            for(int j = 1 ; j < values.size() - 1 ; j++){
                if(values[j-1] < values[j] && values[j] > values[j+1]){
                    ans++;
                }
                if(values[j-1] > values[j] && values[j] < values[j+1]){
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;
    int num1 = 120, num2 = 130;

    cout<<s1.totalWaviness(num1, num2)<<endl;
    
    return 0;
}