# include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int m = g.size(), n = s.size();
        int child = 0, cookies = 0;

        while(child < m && cookies < n){
            if(s[cookies] >= g[child]){
                child++;
            }
            cookies++;
        }
        return child;
    }
};

int main(){
    Solution s1;
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};

    int ans = s1.findContentChildren(g,s);
    // cout<<s1.findContentChildren(g,s)<<endl;
    cout<<ans<<endl;

    return 0;

}