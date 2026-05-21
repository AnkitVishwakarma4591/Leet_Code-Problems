# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(int val : arr1){
            while(!st.count(val) && val > 0){
                st.insert(val);

                val /= 10;
            }
        }

        int result = 0;
        for(int num : arr2){
            while(!st.count(num) && num > 0){
                num /= 10;
            }

            if(num > 0){
                result = max(result, static_cast<int>(log10(num) + 1));
            }
        }
        return result;
    }
};

int main(){
    Solution s1;
    vector<int> arr1 = {1,10,100};
    vector<int> arr2 = {1000};

    cout<<s1.longestCommonPrefix(arr1, arr2)<<endl;
    
    return 0;
}