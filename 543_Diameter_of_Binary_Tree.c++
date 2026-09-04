# include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
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
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}
// Approach 01
// class Solution {
// public:
//     int Height(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }

//         int leftHt = Height(root->left);
//         int rightHt = Height(root->right);

//         return max(leftHt, rightHt) + 1;
//     }

//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root == NULL){
//             return 0;
//         }

//         int leftDia = diameterOfBinaryTree(root->left);
//         int rightDia = diameterOfBinaryTree(root->right);

//         int currDia = Height(root->left) + Height(root->right);

//         return max(currDia, max(leftDia, rightDia));
//     }
// };

class Solution {
public:
    int ans = 0;
    int Height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftHt = Height(root->left);
        int rightHt = Height(root->right);

        ans = max(ans, leftHt + rightHt);

        return max(leftHt, rightHt) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        Height(root);
        return ans;
    }
};

int main(){
    Solution s1;


    vector<int> nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    TreeNode* root = BuildTree(nums);
    preOrder(root);
    cout<<endl;

    cout<<"Diameter : "<<s1.diameterOfBinaryTree(root)<<endl;

    return 0;
}