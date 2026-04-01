# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if (k > 0) {  // move right
            for (int i = 0; i < n; i++) {
                int sum = 0;
                int idx = i + 1;

                for (int j = 0; j < k; j++) {
                    sum += code[idx % n];
                    idx++;
                }

                result[i] = sum;
            }
        } 
        else if (k < 0) {  // move left
            for (int i = 0; i < n; i++) {
                int sum = 0;
                int idx = i - 1;

                for (int j = 0; j < -k; j++) {
                    sum += code[(idx + n) % n];
                    idx--;
                }

                result[i] = sum;
            }
        }

        return result;
    }
};


int main(){
    Solution s1;
    vector<int> code = {5,7,1,4};
    int k = 3;

    for(auto val : s1.decrypt(code, k)){
        cout<<val<<" ";
    }
    return 0;
}