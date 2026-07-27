#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;

        TreeNode* leftpart = invertTree(root->left);
        TreeNode* rightpart = invertTree(root->right);

        root->left = rightpart;
        root->right = leftpart;

        return root;
    }
};

// Build Binary Tree from Level Order Vector
TreeNode* buildTree(vector<int>& arr) {
    if (arr.empty()) return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < arr.size()) {
            curr->left = new TreeNode(arr[i++]);
            q.push(curr->left);
        }

        if (i < arr.size()) {
            curr->right = new TreeNode(arr[i++]);
            q.push(curr->right);
        }
    }

    return root;
}

// Level Order Traversal
void levelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    Solution s1;

    vector<int> arr = {4,2,7,1,3,6,9};

    TreeNode* root = buildTree(arr);

    cout << "Original Tree: ";
    levelOrder(root);

    TreeNode* ans = s1.invertTree(root);

    cout << "Inverted Tree: ";
    levelOrder(ans);

    return 0;
}