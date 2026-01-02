# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& arr) {
        int five = 0,  ten = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] == 5){
                five++;
            }else if(arr[i] == 10){
                if(five > 0){
                    five--;
                    ten++;
                }else{
                    return false;
                }
            }else{
                if(five > 0 && ten > 0){
                    ten--;
                    five--;
                }else if(five >= 3){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};


int main(){
    Solution s1;
    vector<int> bills = {5,5,5,10,20};
    cout<<s1.lemonadeChange(bills)<<endl;
    
    return 0;
}