class LRUCache {
public:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> RUMap;
    int cacheCapacity;
    int cacheSize;
    
    LRUCache(int capacity) {
        cacheCapacity = capacity;
        cacheSize = 0;
    }
    
    void insert(int key, int value) {
        cache.push_back({key, value});
        RUMap[key] = --cache.end();
    }
    
    void remove(list<pair<int, int>>::iterator it) {
        RUMap.erase(it->first);
        cache.erase(it);
    }
    
    int get(int key) {
        if (RUMap.find(key) == RUMap.end()) {
            return -1;
        }
        
        int result = RUMap[key]->second;
        remove(RUMap[key]);
        insert(key, result);
        return result;
    }
    
    void put(int key, int value) {
        if (RUMap.find(key) != RUMap.end()) {
            remove(RUMap[key]);
            insert(key, value);
            return;
        }
        
        if (cacheSize == cacheCapacity) {
            remove(cache.begin());
            cacheSize--;
        }
        insert(key, value);
        cacheSize++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */