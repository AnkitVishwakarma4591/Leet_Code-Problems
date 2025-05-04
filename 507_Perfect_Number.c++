# include <bits/stdc++.h>
using namespace std;

bool checkPerfectNumber(int num) {

    if (num == 1) return false;
    int s = 1;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            s += i;
            if (i != num / i) s += num / i;
        }
    }
    return s == num;
    
}

int main(){
    int num = 28;
    cout<<checkPerfectNumber(num)<<endl;
    int num1 = 7;
    cout<<checkPerfectNumber(num1)<<endl;
    return 0;
}