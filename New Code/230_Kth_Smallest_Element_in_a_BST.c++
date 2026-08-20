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
    if(nums[idx] == -1) return NULL ;

    TreeNode* root = new TreeNode(nums[idx]);

    root->left = BuildTree(nums);
    root->right = BuildTree(nums);

    return root;
}

class Solution {
public:
    int preOrder = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return -1;

        if(root->left){
            int leftAns = kthSmallest(root->left, k);
            if(leftAns != -1){
                return leftAns;
            }
        }
        if(preOrder + 1 == k){
            return root->val;
        }
        preOrder += 1;

        if(root->right){
            int rightAns = kthSmallest(root->right, k);
            if(rightAns != -1){
                return rightAns;
            }
        }
        return -1;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {5,3,2,1,-1,-1,-1,4,-1,-1,6,-1,-1};

    TreeNode* root = BuildTree(nums);

    cout<<s1.kthSmallest(root,3)<<endl;
    return 0;
}