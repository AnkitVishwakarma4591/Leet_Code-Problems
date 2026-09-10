#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int result = 0;

    pair<int, int> solve(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        auto p1 = solve(root->left);
        auto p2 = solve(root->right);

        int totalSum = p1.first + p2.first + root->val;
        int totalCount = p1.second + p2.second + 1;

        int avg = totalSum / totalCount;

        if (avg == root->val) {
            result++;
        }

        return {totalSum, totalCount};
    }

    int averageOfSubtree(TreeNode* root) {
        result = 0;
        solve(root);
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(8);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);

    root->right->right = new TreeNode(6);

    Solution obj;

    cout << "Number of nodes: " << obj.averageOfSubtree(root) << endl;

    return 0;
}