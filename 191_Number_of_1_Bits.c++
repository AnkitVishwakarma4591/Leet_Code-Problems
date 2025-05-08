# include<bits/stdc++.h>
using namespace std;

int hammingWeight(int n){
    int count = 0;
    while(n != 0){
        n &= (n-1);
        count++;
    }
    return count;
}

int main(){
    int n = 11;
    int n1 = 128;

    cout<<hammingWeight(n)<<endl;
    cout<<hammingWeight(n1)<<endl;
    return 0;
}