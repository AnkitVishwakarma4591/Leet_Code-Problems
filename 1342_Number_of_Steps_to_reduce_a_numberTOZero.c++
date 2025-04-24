# include <bits/stdc++.h>
using namespace std;


int numberOfSteps(int num) {

    int step = 0;

    while(num != 0){
        if(num % 2 == 0){
            num = num/2;
        }else{
            num = num-1;
        }
        step++;
    }
    return step;
    
}

int main(){
    int num1 = 14;
    int num2 = 8;
    int num3 = 123;

    cout<<numberOfSteps(num1)<<endl;
    cout<<numberOfSteps(num2)<<endl;
    cout<<numberOfSteps(num3)<<endl;

    return 0;
    
}