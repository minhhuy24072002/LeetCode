struct Node {
        Node* pre;
        Node* next;
        int key;
        Node(int x): key(x), pre(NULL), next(NULL) {};
};
class LRUCache {
public:
    map<int, Node*> key_node;
    map<int, int> key_val;
    int cache_capacity;
    int current_size;
    Node* head;
    Node* tail;
    
    void move_to_head(Node* &head, Node* &tail, Node* &node) {
        if (head == tail && head == nullptr) {
            head = node;
            tail = node;
            return;
        }
        if (node == head) {
            return;
        }
        if (tail == node) {
            tail = tail->pre;
        }
        if (node->pre != nullptr) {
            node->pre->next = node->next;
        }
        if (node->next) {
            node->next->pre = node->pre;
        }
        node->pre = nullptr;
        node->next = head;
        head->pre = node;
        head = node;
        //cout << head -> key << ' ' << tail -> key << endl;
    }
    
    void removeTail(Node* &tail) {
        Node* oldTail = tail;
        tail = tail->pre;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        oldTail->pre = nullptr;
        if (tail == nullptr) {
            head = nullptr;
        }
    }
    
    LRUCache(int capacity) {
        cache_capacity = capacity;
        current_size = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if (key_node[key] == nullptr) {
            return -1;
        }
        move_to_head(head, tail, key_node[key]);
        return key_val[key];
    }
    
    void put(int key, int value) {
        if (key_node[key] == nullptr) {
            if (cache_capacity == current_size) {
                key_node[tail->key] = nullptr;
                removeTail(tail);
                current_size--;
            }
            key_node[key] = new Node(key);
            current_size++;
        }
        move_to_head(head, tail, key_node[key]);
        key_val[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */