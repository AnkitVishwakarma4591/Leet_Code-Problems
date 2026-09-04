#include <iostream>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;

        // Check if k nodes exist
        while(cnt < k){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
            cnt++;
        }

        // Recursively call for rest of the list
        ListNode* prevNode = reverseKGroup(temp, k);

        // Reverse current group
        temp = head; cnt = 0;
        while(cnt < k){
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            cnt++;
        }

        return prevNode;
    }
};

// Helper function to create a linked list
ListNode* createList(int arr[], int n) {
    if(n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for(int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, n);
    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* newHead = sol.reverseKGroup(head, k);

    cout << "Reversed in Groups of " << k << ": ";
    printList(newHead);

    return 0;
}
