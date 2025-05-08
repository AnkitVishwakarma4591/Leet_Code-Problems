# include<bits/stdc++.h>
using namespace std;

vector<string> fizzBuzz(int n){
    vector<string> ans;

    for(int i = 1 ; i <= n ; i++){
        if(i % 15 == 0) ans.push_back("FizzBuzz");
        else if(i % 3 == 0) ans.push_back("Fizz");
        else if(i % 5 == 0) ans.push_back("Buzz");
        else ans.push_back(to_string(i));
    }
    return ans;
}

int main(){
    int n = 3 , n1 = 5 , n2 = 15;
    for(auto val : fizzBuzz(n)){
        cout<<val<<" ";
    }
    cout<<endl;
    for(auto val : fizzBuzz(n1)){
        cout<<val<<" ";
    }
    cout<<endl;
    for(auto val : fizzBuzz(n2)){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}