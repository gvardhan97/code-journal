class LFUCache {
public:
    class Node {
    public:
        int key, val, freq;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            val = v;
            freq = 1;
            prev = next = NULL;
        }
    };

    class DLL {
    public:
        Node *head, *tail;
        int size;

        DLL() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void insert(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size++;
        }

        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        Node* removeLRU() {
            if (size == 0) return NULL;

            Node* node = tail->prev;
            remove(node);
            return node;
        }
    };

    unordered_map<int, Node*> keyMap;
    unordered_map<int, DLL*> freqMap;

    int cap, minFreq;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node) {
        int f = node->freq;

        freqMap[f]->remove(node);

        if (f == minFreq && freqMap[f]->size == 0)
            minFreq++;

        node->freq++;

        if (freqMap.find(node->freq) == freqMap.end())
            freqMap[node->freq] = new DLL();

        freqMap[node->freq]->insert(node);
    }

    int get(int key) {
        if (keyMap.find(key) == keyMap.end())
            return -1;

        Node* node = keyMap[key];

        updateFreq(node);

        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (keyMap.find(key) != keyMap.end()) {
            Node* node = keyMap[key];
            node->val = value;
            updateFreq(node);
            return;
        }

        if (keyMap.size() == cap) {
            Node* lru = freqMap[minFreq]->removeLRU();

            keyMap.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key, value);

        minFreq = 1;

        if (freqMap.find(1) == freqMap.end())
            freqMap[1] = new DLL();

        freqMap[1]->insert(node);
        keyMap[key] = node;
    }
};