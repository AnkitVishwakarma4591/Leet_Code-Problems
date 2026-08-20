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
void preOrder(TreeNode* root){
    if(root == NULL) return;

    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root,0});
        int maxWidth = 0;

        while(q.size() > 0){
            int currLevelSize = q.size();
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

            for(int i = 0 ; i < currLevelSize ; i++){
                auto curr = q.front();
                q.pop();

                if(curr.first->left){
                    q.push({curr.first->left, curr.second*2+1});
                } 

                if(curr.first->right){
                    q.push({curr.first->right, curr.second*2+2});
                }
            }
        }
        return maxWidth;
    }
};

int main(){
    Solution s1;
    vector<int> nums = {1,3,5,-1,-1,3,-1,-1,2,-1,9,-1,-1};

    TreeNode* root = BuildTree(nums);

    preOrder(root);
    cout<<endl;

    cout<<s1.widthOfBinaryTree(root)<<endl;

    return 0;
}