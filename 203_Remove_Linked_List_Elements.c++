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
            head = tail  = newNode;
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

class Solution{
    public:
    ListNode* removeElements(ListNode* head, int val){
        if(!head) return nullptr;

        head->next = removeElements(head->next, val);

        if(head->val == val){
            ListNode* temp = head->next;
            delete head;
            return temp;
        }
        return head;
    }
};

int main(){
    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(6);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(6);

    cout<<"Before Removing Element from list "<<endl;
    l1.printLL();

    Solution s1;

    l1.head = s1.removeElements(l1.head,6);

    cout<<"After Removing Element from List "<<endl;
    l1.printLL();

    return 0;
}