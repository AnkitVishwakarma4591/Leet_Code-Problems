    # include <bits/stdc++.h>
    using namespace std;

    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }
        // If all were 9s, we need an extra digit at the front
        digits.insert(digits.begin(), 1);
        return digits;
    }   

    int main(){
        vector<int> digits = {1,2,3};
        for(int val : plusOne(digits)){
            cout<<val<<" ";
        }

        return 0;
    }