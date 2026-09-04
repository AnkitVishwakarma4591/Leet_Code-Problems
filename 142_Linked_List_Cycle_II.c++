#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                isCycle = true;
                break;
            }
        }

        if (!isCycle) return NULL;

        slow = head;
        ListNode* prev = NULL;
        while (slow != fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        prev->next = NULL;
        return slow;
    }
};

int main() {
    // Input: head = [3,2,0,-4], pos = 1
    vector<int> values = {3, 2, 0, -4};
    int pos = 1;

    // Creating the list
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    ListNode* cycleEntry = nullptr;

    for (int i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
        if (i == pos) {
            cycleEntry = current;
        }
    }

    // Create the cycle
    current->next = cycleEntry;

    // Detect the cycle
    Solution sol;
    ListNode* cycleNode = sol.detectCycle(head);

    if (cycleNode) {
        cout << "Cycle starts at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
