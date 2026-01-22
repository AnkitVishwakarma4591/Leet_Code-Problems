# include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode(int val){
        this->val = val;
        next = NULL;
    }
};

class List{
    public:
    ListNode* head;
    ListNode* tail;

    List(){
        head = tail = NULL;
    }

    void push_back(int val){
        ListNode* newNode = new ListNode(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printLL(){
        ListNode* temp = head;

        while(temp != NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (curr->next != nullptr && curr->val == curr->next->val) {
                int dup = curr->val;

                while (curr != nullptr && curr->val == dup) {
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete temp;
                }

                prev->next = curr;  
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};

int main(){
    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(4);
    l1.push_back(5);

    cout<<"List Before Delete"<<endl;
    l1.printLL();

    Solution s1;

    l1.head = s1.deleteDuplicates(l1.head);

    cout<<"List After Delete"<<endl;
    l1.printLL();
    return 0;
}