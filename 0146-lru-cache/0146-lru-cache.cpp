struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int x, int y) {
        key = x;
        value = y;
    }
};

struct LinkedList {
    Node* head;
    Node* tail;
    LinkedList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    void addFront(Node* node) {
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }
    
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = nullptr;
        node->prev = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> key_node;
    int cacheCapacity;
    int cacheSize;
    LinkedList cache;
    
    LRUCache(int capacity) {
        cacheCapacity = capacity;
        cacheSize = 0;
        cache = LinkedList();
    }
    
    int get(int key) {
        if (key_node.find(key) == key_node.end()) {
            return -1;
        }
        
        Node* tempNode = key_node[key];
        cache.remove(key_node[key]);
        cache.addFront(tempNode);
        
        return tempNode->value;
    }
    
    void put(int key, int value) {
        if (key_node.find(key) != key_node.end()) {
            key_node[key]->value = value;
            Node* tempNode = key_node[key];
            cache.remove(key_node[key]);
            cache.addFront(tempNode);
            return;
        }
        if (cacheSize == cacheCapacity) {
            Node* tempNode = cache.tail->prev;
            key_node.erase(tempNode->key);
            cache.remove(cache.tail->prev);
            cacheSize--;
        }
        Node* newNode = new Node(key, value);
        key_node[key] = newNode;
        cache.addFront(newNode);
        cacheSize++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */