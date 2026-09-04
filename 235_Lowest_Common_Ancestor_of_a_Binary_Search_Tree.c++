/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
# include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = right = NULL;
    }
};

static int idx = -1;
TreeNode* BuildTree(vector<int> nums){
    idx++;

    if(nums[idx] == -1) return NULL;

    TreeNode* root = new TreeNode(nums[idx]);

    root->left = BuildTree(nums);
    root->right = BuildTree(nums);

    return root;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }else if(root->val < p->val && root->val <q->val){
            return lowestCommonAncestor(root->right, p, q);
        }else{
            return root;
        }
    }
};

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

int main(){
    Solution s1;
    vector<int> nums = {6,2,0,-1,-1,4,3,-1,-1,5,-1,-1,8,7,-1,-1,9,-1,-1};

    TreeNode* root = BuildTree(nums);
    TreeNode* p = findNode(root,2);
    TreeNode* q = findNode(root,8);

    cout<<s1.lowestCommonAncestor(root,p,q)->val<<endl;

    return 0;
}