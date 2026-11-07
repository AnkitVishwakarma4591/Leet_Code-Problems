# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P; //wt, idx
    typedef tuple<long, int, int> T; //finTime, wt, idx

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<P, vector<P>, greater<P>> freeServers;

        priority_queue<T, vector<T>, greater<T>> busyServers;

        for(int i = 0; i < n; i++) { //n
            freeServers.push({servers[i], i}); //log(n)
        }

        vector<int> result(m);

        for(int i = 0; i < m; i++) { //
            while(!busyServers.empty() && get<0>(busyServers.top()) <= i) {
                auto [finTime, wt, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({wt, idx});
            }


            if(freeServers.empty()) {
                auto [finTime, wt, idx] = busyServers.top();
                busyServers.pop();
                result[i] = idx;
                busyServers.push({finTime + tasks[i], wt, idx});
            } else { 
                auto [wt, idx] = freeServers.top();
                freeServers.pop();
                result[i] = idx;
                busyServers.push({i + tasks[i], wt, idx});
            }
        }

        return result;
    }
};


int main(){
    Solution s1;
    vector<int> servers = {3,3,2}, tasks = {1,2,3,2,1,2};

    for(int val : s1.assignTasks(servers, tasks)){
        cout<<val<<" ";
    }
    
    return 0;
}