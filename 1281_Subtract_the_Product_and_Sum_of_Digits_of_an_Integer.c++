# include <bits/stdc++.h>
using namespace std;

int subtractProductAndSum(int n){
    int pro = 1;
    int sum = 0;
    while(n != 0){
        int rem = n%10;
        pro *= rem;
        sum += rem;
        n = n/10;
    }
    return pro-sum;
}

int main(){
    int n1 = 234 , n2 = 4421;

    cout<<subtractProductAndSum(n2)<<endl;
    cout<<subtractProductAndSum(n1)<<endl;

    return 0;
}