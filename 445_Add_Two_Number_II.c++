#include <bits/stdc++.h>
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

    void push_front(int val){
        ListNode* newNode = new ListNode(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
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

    void print(){
        ListNode* temp = head;
        while(temp){
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        stack<int> s1, s2;

        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = NULL;

        while(!s1.empty() || !s2.empty() || carry){
            int sum = carry;

            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};

int main(){
    // First number: 7243
    List l1;
    l1.push_back(7);
    l1.push_back(2);
    l1.push_back(4);
    l1.push_back(3);

    // Second number: 564
    List l2;
    l2.push_back(5);
    l2.push_back(6);
    l2.push_back(4);

    Solution obj;
    ListNode* result = obj.addTwoNumbers(l1.head, l2.head);

    // Print result
    ListNode* temp = result;
    while(temp){
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout <<"NULL"<< endl;

    return 0;
}
