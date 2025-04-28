# include <bits/stdc++.h>
using namespace std;

int countEven(int num) {

    int ans = 0;

    for(int i = 1 ; i <= num ; i++){
        int sum = 0;
        int temp = i;
        while(temp > 0){
            int rem = temp % 10;
            sum += rem;
            temp = temp / 10;
        }
        if(sum % 2 == 0){
            ans++;
        }
    }

    return ans;
    
}

int main(){
    int num1 = 4;
    int num2 = 30;

    cout<<countEven(num1)<<endl;
    cout<<countEven(num2)<<endl;

    return 0;
}