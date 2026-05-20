# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result(n);

        // Brute force in O(n^3)
        // for(int i = 0 ; i < n ; i++){
        //     int count = 0;
        //     for(int j = 0 ; j <= i ; j++){
        //         for(int k = 0 ; k <= i ; k++){
        //             if(A[j] == B[k]){
        //                 count++;
        //                 break;
        //             }
        //         }
        //     }
        //     result[i] = count;
        // }
        // return result;

        // Better approach in O(n^2)

        // vector<bool> isPresentA(n+1, false);
        // vector<bool> isPresentB(n+1, false);

        // for(int i = 0 ; i < n ; i++){
        //     isPresentA[A[i]] = true;
        //     isPresentB[B[i]] = true;

        //     int count = 0;
        //     for(int j = 0 ; j < n+1 ; j++){
        //         if(isPresentA[j] == true && isPresentB[j] == true){
        //             count++;
        //         }
        //     }

        //     result[i] = count;
        // }
        // return result;

        // Optimal approach in O(n)
        int count = 0;
        unordered_map<int, int> m;
        for(int i = 0 ; i < n ; i++){

            m[A[i]]++;
            if(m[A[i]] == 2){
                count++;
            }

            m[B[i]]++;
            if(m[B[i]] == 2){
                count++;
            }

            result[i] = count;
        }
        return result;
    }
};

int main(){
    Solution s1;
    vector<int> A = {1,3,2,4};
    vector<int> B = {3,1,2,4};

    for(int val : s1.findThePrefixCommonArray(A, B)){
        cout<<val<<" ";
    }
    
    return 0;
}