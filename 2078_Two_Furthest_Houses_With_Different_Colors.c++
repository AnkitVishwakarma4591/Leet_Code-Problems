# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int result = 0, j = 0;

        // right most distance
        for(int i = 0 ; i < n-1 ; i++){
            if(colors[i] != colors[n-1]){
                result = max(result, (n-1)-i);
                break;
            }
        }

        // leftmost distance
        for(int i = n-1 ; i > 0 ; i--){
            if(colors[i] != colors[0]){
                result = max(result, i);
                break;
            }
        }

        return result;
    }
};

int main(){
    Solution s1;
    vector<int> colors = {4,4,4,11,4,4,11,4,4,4,4,4};

    cout<<s1.maxDistance(colors)<<endl;
    
    return 0;
}