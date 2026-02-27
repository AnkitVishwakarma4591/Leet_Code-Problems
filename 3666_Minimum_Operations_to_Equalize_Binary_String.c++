# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        
        int n = s.length();
        
        int z = 0;
        for(char ch : s) {
            if(ch == '0') z++;
        }

        if(z == 0) return 0;

        set<int> even, odd;

        for(int i = 0; i <= n; i++) {
            if(i == z) continue;
            if(i % 2 == 0) even.insert(i);
            else odd.insert(i);
        }

        queue<int> q;
        q.push(z);

        int steps = 0;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int curr = q.front();
                q.pop();

                if(curr == 0) return steps;

                int lowI = max(0, k - (n - curr));
                int highI = min(k, curr);

                int L = curr + k - 2 * highI;
                int R = curr + k - 2 * lowI;

                L = max(L, 0);
                R = min(R, n);

                set<int>& targetSet = ((curr + k) % 2 == 0) ? even : odd;

                auto it = targetSet.lower_bound(L);

                while(it != targetSet.end() && *it <= R) {
                    q.push(*it);
                    it = targetSet.erase(it); 
                }
            }
            steps++;
        }

        return -1;
    }
};

int main(){
    Solution s1;

    string s = "110";
    int k = 1;

    cout<<s1.minOperations(s, k)<<endl;

    return 0;
}