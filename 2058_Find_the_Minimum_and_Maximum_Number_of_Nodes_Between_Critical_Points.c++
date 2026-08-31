#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

class List {
    ListNode* head;
    ListNode* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        ListNode* newNode = new ListNode(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    ListNode* getHead() {
        return head;
    }
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        // Less than 3 nodes => critical point possible nahi hai
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        int i = 1;

        int preCriticalPos = 0;
        int firstCriticalPos = 0;

        int minDist = INT_MAX;

        while (curr->next != NULL) {

            // Local minima OR local maxima
            if ((curr->val < prev->val && curr->val < curr->next->val) ||
                (curr->val > prev->val && curr->val > curr->next->val)) {

                if (preCriticalPos == 0) {
                    // First critical point
                    preCriticalPos = i;
                    firstCriticalPos = i;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, i - preCriticalPos);

                    preCriticalPos = i;
                }
            }

            i++;
            prev = curr;
            curr = curr->next;
        }

        // Less than 2 critical points
        if (minDist == INT_MAX) {
            return {-1, -1};
        }

        // min distance, max distance
        return {minDist, preCriticalPos - firstCriticalPos};
    }
};

int main() {

    List l;

    // Example:
    // 5 -> 3 -> 1 -> 2 -> 5 -> 1 -> 2
    l.push_front(2);
    l.push_front(1);
    l.push_front(5);
    l.push_front(2);
    l.push_front(1);
    l.push_front(3);
    l.push_front(5);

    Solution s1;

    vector<int> ans = s1.nodesBetweenCriticalPoints(l.getHead());

    cout << "Minimum distance: " << ans[0] << endl;
    cout << "Maximum distance: " << ans[1] << endl;

    return 0;
}