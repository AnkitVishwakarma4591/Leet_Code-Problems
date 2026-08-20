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
    if(nums[idx] == -1){
        return NULL;
    }

    TreeNode* root = new TreeNode(nums[idx]);

    root->left = BuildTree(nums);
    root->right = BuildTree(nums);

    return root;
}

class Solution {
public:
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* sec = NULL;

    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);

        if(prev != NULL && prev->val > root->val){
            if(first == NULL){
                first = prev;
            }
            sec = root;
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {

        inorder(root);
        int temp = first->val;
        first->val = sec->val;
        sec->val = temp;
        
    }
};

void printInorder(TreeNode* root){
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main(){
    Solution s1;
    vector<int> nums = {3,1,-1,-1,4,2,-1,-1,-1};

    TreeNode* root = BuildTree(nums);

    s1.recoverTree(root);

    printInorder(root);

    return 0;
}
