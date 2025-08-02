#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head){
        if (head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* newHead = reverseLinkedList(slow->next);

        // Compare both halves
        ListNode* first = head;
        ListNode* second = newHead;
        bool result = true;
        while (second != NULL) {
            if (first->val != second->val) {
                result = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        // Restore list
        slow->next = reverseLinkedList(newHead);

        return result;
    }
};

// Utility function to create a linked list from vector
ListNode* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    vector<int> input = {1, 2, 2, 1};
    ListNode* head = buildList(input);

    Solution sol;
    bool isPalin = sol.isPalindrome(head);
    cout << (isPalin ? "true" : "false") << endl;

    return 0;
}
