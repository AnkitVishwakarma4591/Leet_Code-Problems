#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }

    void printLL(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};


int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    Solution s;
    s.deleteNode(head->next); // delete node with value 5
    s.printLL(head);
    // list becomes: 4 -> 1 -> 9
    return 0;
}
