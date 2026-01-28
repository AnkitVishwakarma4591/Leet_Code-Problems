# include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
//         int MIN = INT_MAX;
//         vector<string> ans;

//         for (int i = 0; i < list1.size(); i++) {
//             for (int j = 0; j < list2.size(); j++) {
//                 if (list1[i] == list2[j]) {
//                     int sum = i + j;

//                     if (sum < MIN) {
//                         MIN = sum;
//                         ans.clear();
//                         ans.push_back(list1[i]);
//                     } 
//                     else if (sum == MIN) {
//                         ans.push_back(list1[i]);
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Optimize O(n)
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        for (int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;
        }

        int MIN = INT_MAX;
        vector<string> ans;

        for (int j = 0; j < list2.size(); j++) {
            if (mp.count(list2[j])) {
                int sum = j + mp[list2[j]];

                if (sum < MIN) {
                    MIN = sum;
                    ans.clear();
                    ans.push_back(list2[j]);
                } 
                else if (sum == MIN) {
                    ans.push_back(list2[j]);
                }
            }
        }
        return ans;
    }
};


int main(){
    Solution s1;

    vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};


    for(auto val : s1.findRestaurant(list1, list2)){
        cout<<val<<" ";
    }

    return 0;
}