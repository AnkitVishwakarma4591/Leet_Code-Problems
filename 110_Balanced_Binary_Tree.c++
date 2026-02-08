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

void BinaryTree(TreeNode* root){
    if(root == NULL) return;
    cout<<root->val<<" ";

    BinaryTree(root->left);
    BinaryTree(root->right);
}

class Solution {
public:
    int Height(TreeNode* root){
        if(root == NULL) return 0;

        int leftHeight = Height(root->left);
        if(leftHeight == -1) return -1;
        int rightHeight = Height(root->right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight-rightHeight) > 1) return -1;

        return max(leftHeight, rightHeight) + 1;

    }
    bool isBalanced(TreeNode* root) {
        return Height(root) != -1;
    }
};

int main(){
    Solution s1;

    vector<int> nums = {
        3,
        9, -1, -1,
        20,
        15, -1, -1,
        7, -1, -1
    };

    idx = -1;   // IMPORTANT
    TreeNode* root = BuildTree(nums);

    BinaryTree(root);
    cout << endl;

    cout << s1.isBalanced(root) << endl; // prints 1 (true)

    return 0;
}
