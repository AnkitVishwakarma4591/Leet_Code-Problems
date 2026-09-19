# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xi, yi;

        if(x1 > xCenter){
            xi = x1;
        }else if(x2 < xCenter){
            xi = x2;
        }else{
            xi = xCenter;
        }

        if(y1 > yCenter){
            yi = y1;
        }else if(y2 < yCenter){
            yi = y2;
        }else{
            yi = yCenter;
        }

        int d = sqrt((xi - xCenter) * (xi - xCenter) + (yi - yCenter) * (yi - yCenter));

        return d <= radius;
    }
};

int main(){
    Solution s1;
    int radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1;

    cout<<s1.checkOverlap(radius, xCenter, yCenter, x1, y1, x2, y2)<<endl;
    
    return 0;
}