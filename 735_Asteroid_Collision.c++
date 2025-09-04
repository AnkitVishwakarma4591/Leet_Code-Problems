# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        vector<int> st;

        for (int x : nums) {
            bool destroyed = false;

            while (!st.empty() && st.back() > 0 && x < 0) {
                if (st.back() < -x) {
                    st.pop_back();
                    continue; // keep checking
                } else if (st.back() == -x) {
                    st.pop_back();
                }
                destroyed = true;
                break;
            }

            if (!destroyed)
                st.push_back(x);
        }

        return st;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {5,10,-5};

    for(auto val : s1.asteroidCollision(nums)){
        cout<<val<<" ";
    }

    return 0;
}
