#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BSTIterator definition
class BSTIterator {
public:
    stack<TreeNode*> s;

    void storeLeftNodes(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }
    
    int next() {
        TreeNode* ans = s.top();
        s.pop();
        storeLeftNodes(ans->right);
        return ans->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

// Build BST from level-order input
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front(); q.pop();

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

int main() {
    vector<string> input = {"7", "3", "15", "null", "null", "9", "20"};

    // Step 1: Build the BST
    TreeNode* root = buildTree(input);

    // Step 2: Create BSTIterator instance
    BSTIterator* obj = new BSTIterator(root);

    // Step 3: Simulate commands
    vector<string> commands = {"BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"};

    for (int i = 1; i < commands.size(); ++i) {
        if (commands[i] == "next") {
            cout << "next() -> " << obj->next() << endl;
        } else if (commands[i] == "hasNext") {
            cout << "hasNext() -> " << (obj->hasNext() ? "true" : "false") << endl;
        }
    }

    return 0;
}
