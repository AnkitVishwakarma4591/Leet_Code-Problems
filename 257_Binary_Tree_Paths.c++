#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution class
class Solution {
public:
    void allPaths(TreeNode* root, string path, vector<string> &ans) {
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }

        if (root->left)
            allPaths(root->left, path + "->" + to_string(root->left->val), ans);

        if (root->right)
            allPaths(root->right, path + "->" + to_string(root->right->val), ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) return ans;
        string path = to_string(root->val);
        allPaths(root, path, ans);
        return ans;
    }
};

// Helper function to build binary tree from vector input
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Main function
int main() {
    vector<string> input = {"1", "2", "3", "null", "5"};

    TreeNode* root = buildTree(input);

    Solution sol;
    vector<string> result = sol.binaryTreePaths(root);

    cout << "Binary Tree Paths:\n";
    for (const string& path : result) {
        cout << path << endl;
    }

    return 0;
}
