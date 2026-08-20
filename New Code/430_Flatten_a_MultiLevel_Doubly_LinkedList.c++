#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL){
            return head;
        }

        Node* curr = head;
        while(curr != NULL){
            if(curr->child != NULL){
                //flatten the child nodes
                Node* next = curr->next;
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = NULL;

                //find tail
                while(curr->next != NULL){
                    curr = curr->next;
                }

                //attach tail with next ptr
                if(next != NULL){
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;  
    }
};

// Helper function to print the flattened list
void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Sample multilevel doubly linked list creation
Node* createSampleList() {
    // Level 1: 1 - 2 - 3 - 4 - 5 - 6
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;

    // Level 2: 7 - 8 - 9 - 10
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    n7->next = n8; n8->prev = n7;
    n8->next = n9; n9->prev = n8;
    n9->next = n10; n10->prev = n9;

    // Level 3: 11 - 12
    Node* n11 = new Node(11);
    Node* n12 = new Node(12);
    n11->next = n12; n12->prev = n11;

    // Linking child pointers
    n3->child = n7;   // 3 -> 7
    n8->child = n11;  // 8 -> 11

    return n1;
}

int main() {
    Node* head = createSampleList();
    Solution sol;
    Node* flatHead = sol.flatten(head);

    cout << "Flattened list: ";
    printList(flatHead);

    return 0;
}
