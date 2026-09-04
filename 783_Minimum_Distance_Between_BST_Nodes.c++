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
    TreeNode* prev = NULL;

    int minDiffInBST(TreeNode* root) {
        if(root == NULL){
            return INT_MAX;
        }

        int ans = INT_MAX;

        if(root->left){
            int leftMin = minDiffInBST(root->left);
            ans = min(ans, leftMin);
        }
        if(prev != NULL){
            ans = min(ans, root->val - prev->val);
        }
        prev = root;
        
        if(root->right){
            int rightMin = minDiffInBST(root->right);
            ans = min(ans, rightMin);
        }

        return ans;
        
    }
};

int main(){
    Solution s1;
    vector<int> nums = {4,2,1,-1,-1,3,-1,-1,6,-1,-1};

    TreeNode* root = BuildTree(nums);

    cout<<s1.minDiffInBST(root)<<endl;
    
    return 0;
}