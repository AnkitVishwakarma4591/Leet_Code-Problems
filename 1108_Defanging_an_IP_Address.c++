# include <bits/stdc++.h>
using namespace std;

string defangIPaddr(string address) {
    string ans = "";

    for(int i = 0 ; i < address.length() ; i++){
        if(address[i] == '.'){
            ans += "[.]";
        }else{
            ans += address[i];
            
        }
    }
    return ans;
    
}

int main(){
    string address = "1.1.1.1";
    cout<<defangIPaddr(address)<<endl;
    
    return 0;
}