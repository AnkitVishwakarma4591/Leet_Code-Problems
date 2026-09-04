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

TreeNode* findNode(TreeNode* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    
    TreeNode* left = findNode(root->left, val);
    if (left) return left;

    return findNode(root->right, val);
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == p->val || root->val == q->val){
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if(leftLCA && rightLCA){
            return root;
        }
        else if(leftLCA != NULL){
            return leftLCA;
        }
        else{
            return rightLCA;
        }
    }
};

int main(){
    vector<int> nums = {3,5,6,-1,-1,2,7,-1,-1,4,-1,-1,1,0,-1,-1,8,-1,-1};
    TreeNode* root = BuildTree(nums);
    
    TreeNode* p = findNode(root, 5);
    TreeNode* q = findNode(root, 1);
    Solution s1;
    TreeNode* ans = s1.lowestCommonAncestor(root,p,q);

    if (ans)
        cout << "LCA: " << ans->val << endl;
    else{
        cout << "LCA not found" << endl;
    }

    return 0;
}