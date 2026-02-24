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
TreeNode* BuildTree(vector<int> &nums){
    idx++;
    if(nums[idx] == -1) return NULL;

    TreeNode* root = new TreeNode(nums[idx]);

    root->left = BuildTree(nums);
    root->right = BuildTree(nums);

    return root;
}

class Solution {
public:
    
    int depth_first_Search(TreeNode* root, int curr) {
        if(root == NULL) return 0;
        

        curr = curr * 2 + root->val;
        
        if(root->left == NULL && root->right == NULL) {
            return curr;
        }

        return depth_first_Search(root->left, curr) + depth_first_Search(root->right, curr);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        return depth_first_Search(root, 0);
    }
};

int main(){
    Solution s1;

    vector<int> nums = {1,0,0,-1,-1,1,-1,-1,1,0,-1,-1,1,-1,-1};
    TreeNode* root = BuildTree(nums);

    cout<<s1.sumRootToLeaf(root)<<endl;
    return 0;
}