# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Check if there is an overlap along both X and Y axes
        bool x_overlap = min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]);
        bool y_overlap = min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]);
        
        return x_overlap && y_overlap;
    }
};

int main(){
    Solution s1;
    vector<int> vec1 = {0,0,2,2}, vec2 = {1,1,3,3};

    cout<<s1.isRectangleOverlap(vec1, vec2)<<endl;
    
    return 0;
}