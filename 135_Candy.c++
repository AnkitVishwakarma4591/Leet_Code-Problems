# include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {

        // Optimal approach T.C = O(N), S.C = O(1)

        int n = ratings.size();

        int Sum = 1, i = 1;

        while(i < n){
            if(ratings[i] == ratings[i-1]){
                Sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak += 1;
                Sum += peak;
                i++;
            }
            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]){
                Sum += down;
                i++;
                down++;
            }
            if(down > peak){
                Sum += (down - peak);
            }
        }
        return Sum;

        // Better approach T.C = O(2n), S.C = O(N)
        // int n = ratings.size();

        // vector<int> left(n);
        // left[0] = 1;

        // for(int i = 1 ; i < n ; i++){
        //     if(ratings[i] > ratings[i-1]){
        //         left[i] = left[i-1] + 1;
        //     }else{
        //         left[i] = 1;
        //     }
        // }
        // int curr = 1, right = 1;
        // int Sum = max(1, left[n-1]);

        // for(int i = n-2 ; i >= 0 ; i--){
        //     if(ratings[i] > ratings[i+1]){
        //         curr = right + 1;
        //         right = curr;
        //     }else{
        //         curr = 1;
        //         right = 1;
        //     }
        //     Sum += max(left[i], curr);
        // }
        // return Sum;



        // // Brute force approach T.C = O(3N), S.C = O(N)

        // int n = ratings.size();

        // vector<int> left(n);
        // vector<int> right(n);

        // left[0] = 1, right[n-1] = 1;

        // for(int i = 1 ; i < n ; i++){
        //     if(ratings[i] > ratings[i-1]){
        //         left[i] = left[i-1]+1;
        //     }else{
        //         left[i] = 1;
        //     }
        // }
        // for(int i = n-2 ; i >= 0 ; i--){
        //     if(ratings[i] > ratings[i+1]){
        //         right[i] = right[i+1]+1;
        //     }else{
        //         right[i] = 1;
        //     }
        // }
        // int Sum = 0;
        // for(int i = 0 ; i < n ; i++){
        //     Sum += max(left[i],right[i]);
        // }
        // return Sum;
    }
};


int main(){
    Solution s1;
    vector<int> ratings = {1,0,2};

    cout<<s1.candy(ratings)<<endl;
    
    return 0;
}