# include<bits/stdc++.h>
using namespace std;

int countOdds(int low, int high){
    int count = 0;
    for(int i = low ; i <= high ; i++){
        if(i % 2 != 0){
            count++;
        }
    }
    return count;
    // return (high + 1 >> 1)-(low >> 1);
}

int main(){
    int low = 3 , high = 7;

    cout<<countOdds(low,high)<<endl;
    return 0;
}