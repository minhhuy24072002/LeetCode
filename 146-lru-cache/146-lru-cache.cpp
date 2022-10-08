class LRUCache {
public:
    int size = 0;
    int LRUCacheCapacity;
    vector<int> cache;
    vector<int> count;
    deque<int> lruQueue;
    
    LRUCache(int capacity) {
        LRUCacheCapacity = capacity;
        cache = vector<int>(100001);
        count = vector<int>(100001);
    }
    
    int get(int key) {
        if (cache[key] > 0) {
            lruQueue.push_front(key);
            count[key]++;
        }
        return cache[key] - 1;
    }
    
    void put(int key, int value) {
        while (lruQueue.size() > 0 && count[lruQueue.back()] > 1) {
            count[lruQueue.back()]--;
            lruQueue.pop_back();    
        }

        if (size == LRUCacheCapacity && cache[key] == 0) {
            cache[lruQueue.back()] = 0;
            count[lruQueue.back()]--;
            lruQueue.pop_back();
            size--;
        }
        if (cache[key] > 0) {
            size--;
        }

        cache[key] = value + 1;
        lruQueue.push_front(key);
        count[key]++;
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */