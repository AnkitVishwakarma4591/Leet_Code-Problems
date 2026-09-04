#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = NULL;

        while(first != NULL && sec != NULL){
            ListNode* third = sec->next;

            sec->next = first;
            first->next = third;

            if(prev != NULL){
                prev->next = sec;
            }
            else{
                head = sec;
            }

            prev = first;
            first = third;
            if(third != NULL){
                sec = third->next;
            }
            else{
                sec = NULL;
            }
        }
        return head;
    }
};

/* Helper function to print linked list */
void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

/* Helper function to create a linked list from array */
ListNode* createList(const vector<int>& arr) {
    if(arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for(size_t i = 1; i < arr.size(); ++i) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    vector<int> values = {1, 2, 3, 4};
    ListNode* head = createList(values);
    
    Solution sol;
    ListNode* swapped = sol.swapPairs(head);
    
    cout << "Swapped List: ";
    printList(swapped);

    return 0;
}
