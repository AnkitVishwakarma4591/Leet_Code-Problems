#include <bits/stdc++.h>
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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* reverseHead = reverse(slow);

        ListNode* temp1 = head;
        ListNode* temp2 = reverseHead;

        int ans = 0;

        while (temp2 != NULL) {
            ans = max(ans, temp1->val + temp2->val);

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return ans;
    }
};

// Helper function to create linked list
ListNode* createList(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

int main() {
    Solution s1;

    vector<int> arr = {5, 4, 2, 1};

    ListNode* head = createList(arr);

    cout << s1.pairSum(head) << endl;

    return 0;
}