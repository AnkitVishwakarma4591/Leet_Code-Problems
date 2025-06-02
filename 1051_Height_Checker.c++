    # include <bits/stdc++.h>
    using namespace std;

    int heightChecker(vector<int>& heights) {

        vector<int> expected = heights;
        sort(expected.begin(),expected.end());
        
        int count = 0;
        for(int i = 0 ; i < heights.size() ; i++){
            if(heights[i] != expected[i]){
                count++;
            }
        }
    return count;  
    }

    int main(){
        vector<int> heigths = {1,1,4,2,1,3};

        cout<<heightChecker(heigths)<<endl;

        return 0;
    }