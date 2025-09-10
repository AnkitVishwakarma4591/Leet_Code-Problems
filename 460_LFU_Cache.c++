#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    struct Node {
        int key, value, freq;
        Node(int k, int v) : key(k), value(v), freq(1) {}
    };

    int capacity, minFreq;
    unordered_map<int, list<Node>::iterator> keyNode; // key -> Node iterator
    unordered_map<int, list<Node>> freqList;          // freq -> list of Nodes

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0 || keyNode.find(key) == keyNode.end())
            return -1;

        auto it = keyNode[key];
        int val = it->value;
        int freq = it->freq;

        // remove from current freq list
        freqList[freq].erase(it);
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // add to next freq list
        freqList[freq + 1].push_front(Node(key, val));
        keyNode[key] = freqList[freq + 1].begin();
        keyNode[key]->freq = freq + 1;

        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            // update existing
            keyNode[key]->value = value;
            get(key); // increase frequency
            return;
        }

        if (keyNode.size() == capacity) {
            // remove LFU node
            auto it = freqList[minFreq].back();
            int delKey = it.key;
            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty()) freqList.erase(minFreq);
            keyNode.erase(delKey);
        }

        // insert new node
        freqList[1].push_front(Node(key, value));
        keyNode[key] = freqList[1].begin();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    // Example usage:
    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    cout << lfu.get(1) << endl; // returns 1
    lfu.put(3, 3);              // evicts key 2
    cout << lfu.get(2) << endl; // returns -1
    cout << lfu.get(3) << endl; // returns 3
    lfu.put(4, 4);              // evicts key 1
    cout << lfu.get(1) << endl; // returns -1
    cout << lfu.get(3) << endl; // returns 3
    cout << lfu.get(4) << endl; // returns 4
    return 0;
}
