/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == NULL) return true;

        if(min != NULL && root->val <= min->val){
            return false;
        }
        if(max != NULL && root->val >= max->val){
            return false;
        }

        return helper(root->left, min, root) 
            && helper(root->right, root, max);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};

int main(){
    Solution s1;
    vector<int> nums = {5,1,-1,-1,4,3,-1,-1,6,-1,-1};

    TreeNode* root = BuildTree(nums);

    cout<<s1.isValidBST(root)<<endl;

    return 0;
}