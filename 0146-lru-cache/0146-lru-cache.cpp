class LRUCache {
public:
    class Block {
        public:
            int key;
            int value;
            Block(int x, int y) {
                key = x;
                value = y;
            }
    };
    int cacheCapacity;
    int currentSize;
    list<Block> cache;
    unordered_map<int, list<Block>::iterator> block;
    
    LRUCache(int capacity) {
        cacheCapacity = capacity;
        currentSize = 0;
    }
    
    int get(int key) {
        if (block.find(key) == block.end()) {
            return -1;
        }
        
        Block temp = *block[key];
        cache.erase(block[key]);
        cache.push_back(temp);
        block[key] = cache.end();
        block[key]--;
        return temp.value;
    }
    
    void put(int key, int value) {
        if (block.find(key) != block.end()) {
            cache.erase(block[key]);
            cache.push_back(Block(key, value));
            block[key] = cache.end();
            block[key]--;
        } else {
            if (currentSize == cacheCapacity) {
                Block lastBlock = cache.front();
                cache.erase(cache.begin());
                block.erase(lastBlock.key);
                currentSize--;
            }
            cache.push_back(Block(key, value));
            block[key] = cache.end();
            block[key]--;
            currentSize++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */