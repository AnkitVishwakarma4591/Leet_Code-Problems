#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};

class Solution {
public:
    TreeNode* helper(vector<int>& nums, int st, int end) {
        if (st > end) return NULL;

        int mid = st + (end - st) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, st, mid - 1);
        root->right = helper(nums, mid + 1, end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

// 🔁 Function to print Level Order (LeetCode-style) with nulls
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "null\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    vector<string> result;

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            result.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back("null");
        }
    }

    // Remove trailing "null"s (as LeetCode does)
    while (!result.empty() && result.back() == "null")
        result.pop_back();

    // Print in comma-separated format
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ",";
    }
    cout << endl;
}

// 🔰 Main function
int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution sol;
    TreeNode* bstRoot = sol.sortedArrayToBST(nums);

    cout << "Level-order output: ";
    printLevelOrder(bstRoot);

    return 0;
}
