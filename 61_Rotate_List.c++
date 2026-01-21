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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0){
            return head;
        }

        int n = 1;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
            n++;
        }

        k = k % n;
        if(k == 0) return head;

        tail->next = head;

        ListNode* newTail = head;
        for(int i = 0 ; i < n - k - 1 ; i++){
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};


int main(){
    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);

    cout<<"List Before Rotate"<<endl;
    l1.printLL();

    Solution s1;
    int k = 2;
    l1.head = s1.rotateRight(l1.head,k);

    cout<<"List After Rotate"<<endl;
    l1.printLL();
    
    return 0;
}