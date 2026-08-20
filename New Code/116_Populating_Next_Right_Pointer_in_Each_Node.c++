#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node* prev = NULL;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                if (prev) prev->next = curr;
                prev = curr;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            // Last node of this level
            prev->next = NULL;
        }

        return root;
    }
};

// Helper to build a perfect binary tree from array [1,2,3,4,5,6,7]
Node* buildTree() {
    vector<Node*> nodes(8, nullptr); // 0th index unused
    for (int i = 1; i <= 7; ++i)
        nodes[i] = new Node(i);

    for (int i = 1; i <= 3; ++i) {
        nodes[i]->left = nodes[2 * i];
        nodes[i]->right = nodes[2 * i + 1];
    }

    return nodes[1]; // root node
}

// Helper to print tree levels with next pointers
void printLevels(Node* root) {
    Node* level = root;
    while (level) {
        Node* curr = level;
        while (curr) {
            cout << curr->val << "->";
            curr = curr->next;
        }
        cout << "NULL" << endl;
        level = level->left;
    }
}

int main() {
    Node* root = buildTree();

    Solution sol;
    sol.connect(root);

    printLevels(root);

    return 0;
}
