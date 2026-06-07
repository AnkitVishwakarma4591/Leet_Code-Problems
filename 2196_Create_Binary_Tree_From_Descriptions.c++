# include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class TreeNode{
//     public:

// };
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet; // they can never be root of the tree

        for(auto &vec : descriptions){
            int parent = vec[0];
            int child = vec[1];
            int isleft = vec[2];

            if(mp.find(parent) == mp.end()){
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end()){
                mp[child] = new TreeNode(child);
            }

            if(isleft == 1){
                mp[parent]->left = mp[child];
            }else{
                mp[parent]->right = mp[child];
            }

            childSet.insert(child);
        }

        // find the root
        for(auto &vec : descriptions){
            int parent = vec[0];
            if(childSet.find(parent) == childSet.end()){
                return mp[parent];
            }
        }
        return NULL;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> descriptions = {{20,15,1}, {20,17,0}, {50,20,1}, {50,80,0}, {80,19,1}};
    TreeNode* ans = s1.createBinaryTree(descriptions);
    // for(auto val : s1.createBinaryTree(descriptions)){
    //     cout<<val<<" "
    // }
    cout<<ans->val<<endl;
    return 0;
}