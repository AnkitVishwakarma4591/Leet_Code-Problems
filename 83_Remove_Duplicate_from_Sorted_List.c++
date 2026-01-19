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
        if(head == nullptr) return head;

        ListNode* curr = head;

        while(curr != nullptr && curr->next != nullptr){
            if(curr->val == curr->next->val){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};

int main(){
    List l1;
    l1.push_back(1);
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(3);

    cout << "Before removing duplicates:\n";
    l1.printLL();

    Solution s1;
    l1.head = s1.deleteDuplicates(l1.head);

    cout << "After removing duplicates:\n";
    l1.printLL();


    return 0;

}