class MyCircularQueue {
public:
    int capacity;
    int currentSize;
    int front;
    int rear;
    vector<int> qu;
    MyCircularQueue(int k) {
        qu = vector<int>(k);
        capacity = k;
        currentSize = 0;
        front = 0;
        rear = -1;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        
        rear = (rear + 1) % capacity; 
        qu[rear] = value;
        currentSize++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        
        front = (front + 1) % capacity;
        currentSize--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return qu[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return qu[rear];
    }
    
    bool isEmpty() {
        return currentSize == 0;
    }
    
    bool isFull() {
        return currentSize == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */