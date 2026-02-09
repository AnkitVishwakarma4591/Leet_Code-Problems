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
TreeNode* insert(TreeNode* root, int val){
    if(root == NULL) return new TreeNode(val);
    if(val < root->val){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    return root;
}

TreeNode* buildBST(vector<int> nums){
    TreeNode* root = NULL;
    for(int val : nums){
        root = insert(root, val);
    }
    return root;
}

class Solution {
public:
    void inOrder(TreeNode* root, vector<int> &nums){
        if(root == NULL) return;

        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);

    }
    TreeNode* BuildBST(vector<int> &nums, int st, int end){
        if(st > end) return NULL;

        int mid = st + (end - st)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = BuildBST(nums, st, mid-1);
        root->right = BuildBST(nums, mid+1, end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inOrder(root, nums);
        return BuildBST(nums, 0, nums.size()-1);
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,-1,2,-1,3,-1,4,-1,-1};
    TreeNode* root = buildBST(nums);

    s1.balanceBST(root);
    
    return 0;
}