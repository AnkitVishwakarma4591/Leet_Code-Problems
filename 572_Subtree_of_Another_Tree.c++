#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to convert vector to binary tree (level-order)
TreeNode* vectorToTree(const vector<int>& nodes) {
    if (nodes.empty()) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (i < nodes.size()) {
        TreeNode* current = q.front(); q.pop();

        if (i < nodes.size()) {
            current->left = new TreeNode(nodes[i++]);
            q.push(current->left);
        }
        if (i < nodes.size()) {
            current->right = new TreeNode(nodes[i++]);
            q.push(current->right);
        }
    }

    return root;
}

class Solution {
public:
    bool isIdentical(TreeNode* p, TreeNode* q){
        if (p == nullptr || q == nullptr)
            return p == q;
        return p->val == q->val &&
               isIdentical(p->left, q->left) &&
               isIdentical(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr || subRoot == nullptr)
            return root == subRoot;

        if (root->val == subRoot->val && isIdentical(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main() {
    // Input as vector
    vector<int> rootVec = {3, 4, 5, 1, 2};
    vector<int> subRootVec = {4, 1, 2};

    // Build trees
    TreeNode* root = vectorToTree(rootVec);
    TreeNode* subRoot = vectorToTree(subRootVec);

    // Check subtree
    Solution sol;
    cout << (sol.isSubtree(root, subRoot) ? "True" : "False") << endl;

    return 0;
}
