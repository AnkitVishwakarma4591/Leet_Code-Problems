# include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val = data;
        left = right = NULL;
    }
};
TreeNode * buildTree(const vector<int> & nums, int &idx){
    idx++;
    if(idx >= (int)nums.size() || nums[idx] == -1){
        return NULL;
    }

    TreeNode* root = new TreeNode(nums[idx]);

    root->left = buildTree(nums, idx);
    root->right = buildTree(nums, idx);

    return root;
}

TreeNode * buildTree(const vector<int> & nums){
    int idx = -1;
    return buildTree(nums, idx);
}
class Solution{
    public:
    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return max(leftHeight, rightHeight) + 1;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {3, 1, -1, -1, 20, 15, -1, -1, 7, -1, -1};
    TreeNode* root = buildTree(nums);
    cout<<s1.maxDepth(root)<<endl;
    return 0;
}