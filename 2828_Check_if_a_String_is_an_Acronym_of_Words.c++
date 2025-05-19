    # include <bits/stdc++.h>
    using namespace std;


    bool isAcronym(vector<string>& words, string s) {

        string acronym = "";

        for(int i = 0 ; i < words.size() ; i++){
            string copy = words[i];

            acronym += copy[0];
        }
        
        return acronym == s;
    }

    int main(){
        vector<string> words = {"alice","bob","charlie"};
        string s = "abc";
        cout<<isAcronym(words,s)<<endl;
        return 0;
    }