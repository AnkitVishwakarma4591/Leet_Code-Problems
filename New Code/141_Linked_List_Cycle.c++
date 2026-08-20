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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> values = {3, 2, 0, -4};
    int pos = 1; // Create cycle at index 1

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

    Solution sol;
    bool hasCycle = sol.hasCycle(head);

    cout << (hasCycle ? "true" : "false") << endl;

    return 0;
}
