#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:

    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head;
    Node* tail;
    unordered_map<int, Node*> m;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    void delNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }

        Node* ansNode = m[key];
        int ans = ansNode->val;

        m.erase(key);
        delNode(ansNode);
        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
            delete oldNode; // free memory
        }

        if (m.size() == limit) {
            Node* lru = tail->prev;
            m.erase(lru->key);
            delNode(lru);
            delete lru; // free memory
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }

    // Destructor to clean up all nodes
    ~LRUCache() {
        Node* curr = head;
        while (curr != NULL) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

// ---------- Test Case ----------
int main() {
    LRUCache cache(2); // Capacity = 2

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;   // Returns 1

    cache.put(3, 3); // Evicts key 2
    cout << cache.get(2) << endl;   // Returns -1 (not found)

    cache.put(4, 4); // Evicts key 1
    cout << cache.get(1) << endl;   // Returns -1 (not found)
    cout << cache.get(3) << endl;   // Returns 3
    cout << cache.get(4) << endl;   // Returns 4

    return 0;
}
