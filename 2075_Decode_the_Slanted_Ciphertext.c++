# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int l = encodedText.size();
        int cols = l/rows;
        string originalText;
        for(int col = 0 ; col < cols ; col++){
            for(int j = col; j < l ; j+= (cols+1)){
                originalText += encodedText[j];
            }
        }

        while(!originalText.empty() && originalText.back() == ' '){
            originalText.pop_back();
        }

        return originalText;
    }
};


int main(){
    Solution s1;
    string encodedText = "iveo    eed   l te   olc";
    int rows = 4;

    cout<<s1.decodeCiphertext(encodedText, rows)<<endl;
    
    return 0;
}