struct Node {
    int key;
    int value;
    int freq;
    Node* prev;
    Node* next;
    Node(int x, int y) {
        key = x;
        value = y;
        freq = 1;
    }
};

struct List {
    Node* head;
    Node* tail;
    int size;
    
    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        size = 0;
        head->next = tail;
        tail->prev = head;
    }
    
    void addFront(Node* node) {
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
        size++;
    }
    
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
        size--;
    }
};

class LFUCache {
public:
    unordered_map<int, List> freqList;
    unordered_map<int, Node*> key_node;
    int cacheCapacity;
    int cacheSize;
    int minFreq;
    
    LFUCache(int capacity) {
        cacheCapacity = capacity;
        cacheSize = 0;
        minFreq = 0;
    }
    
    void updateFreqList(Node* node) {
        freqList[node->freq].remove(node);
        if (freqList[minFreq].size == 0) {
            minFreq++;
        }
        
        node->freq++;
        freqList[node->freq].addFront(node);
    }
    
    int get(int key) {
        if (key_node.find(key) == key_node.end()) {
           return -1;
        }
        
        updateFreqList(key_node[key]);
        return key_node[key]->value;
    }
    
    void put(int key, int value) {
        if (cacheCapacity == 0) {
            return;
        }
        if (key_node.find(key) != key_node.end()) {
            updateFreqList(key_node[key]);
            key_node[key]->value = value;
            return;
        }
        if (cacheSize == cacheCapacity) {
            Node* tempNode = freqList[minFreq].tail->prev;
            freqList[minFreq].remove(tempNode);
            key_node.erase(tempNode->key);
            cacheSize--;
        }
        
        minFreq = 1;
        Node* tempNode = new Node(key, value);
        freqList[1].addFront(tempNode);
        key_node[key] = tempNode;
        cacheSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */