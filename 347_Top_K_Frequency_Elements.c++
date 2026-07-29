# include <bits/stdc++.h>
using namespace std;

// Brute force approach
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//        unordered_map<int, int> m;
//        for(int val : nums){
//             m[val]++;
//        }

//        vector<pair<int, int>> p;
//        for(auto val : m){
//             p.push_back(val);
//        }
//        sort(p.begin(), p.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
//             return a.second > b.second;
//         });
//        vector<int> ans;
//        for(int i = 0 ; i < k ; i++){
//             ans.push_back(p[i].first);
//        }
//        return ans;
//     }
// };

class Solution {
public:
    typedef pair<int, int> p;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //min-heap
        priority_queue<p, vector<p>, greater<p>> pq;
        
        //count frequency of each element
        // Worst Case - n distinct elements are stored, so, space O(n)
        unordered_map<int, int> mp;
        for(int i : nums)
            mp[i]++;
        
        //Push in min-heap and maintain size k
        for(auto it:mp) {
            pq.push({it.second, it.first});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        
        //Pick all top K elements
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};


int main(){
    Solution s1;
    vector<int> nums = {1,2,1,2,1,2,3,1,3,2};
    int k = 2;

    for(int val : s1.topKFrequent(nums, k)){
        cout<<val<<" ";
    }
    return 0;
}