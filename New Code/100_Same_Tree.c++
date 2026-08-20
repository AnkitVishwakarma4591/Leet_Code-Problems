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

// Function to convert vector to tree (complete binary tree assumption)
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr || q == nullptr)
            return p == q;

        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);

        return isLeftSame && isRightSame && p->val == q->val;
    }
};

int main() {
    vector<int> vecP = {1, 2, 3};
    vector<int> vecQ = {1, 2, 3};

    TreeNode* p = vectorToTree(vecP);
    TreeNode* q = vectorToTree(vecQ);

    Solution sol;
    cout << (sol.isSameTree(p, q) ? "True" : "False") << endl;

    return 0;
}
