# include <iostream>
# include <vector>
# include <string>
using namespace std;

vector<char>  reverseString(vector<char> &s){
    int n = s.size();
    int st = 0 , end = n-1;

    while(st < end){
        swap(s[st++],s[end--]);
    }
    return s;
}

int main(){
    vector<char> s = {'h','e','l','l','o'};

    for(auto c : reverseString(s)){
        cout<<c<<" ";
    }
    return 0;
}