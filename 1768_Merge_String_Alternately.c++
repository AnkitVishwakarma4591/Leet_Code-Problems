    # include <bits/stdc++.h>
    using namespace std;

    string mergeAlternately(string w1, string w2) {

        int i = 0 , j = 0;
        string ans = "";

        while(i < w1.size() || j < w2.size()){
            if(i < w1.size()) ans += w1[i++];
            if(j < w2.size()) ans += w2[j++];
        }
        return ans;
    }

    int main(){
        string w1 = "abc", w2 = "pqr";
        cout<<mergeAlternately(w1,w2)<<endl;
        return 0;
    }