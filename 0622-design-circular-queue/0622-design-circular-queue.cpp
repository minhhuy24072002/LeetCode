class MyCircularQueue {
public:
    int capacity;
    int currentSize;
    int front;
    int rear;
    vector<int> myQueue;
    
    MyCircularQueue(int k) {
        capacity = k;
        currentSize = 0;
        front = 0;
        rear = k - 1;
        myQueue = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % capacity;
        myQueue[rear] = value;
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
        return myQueue[front];
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return myQueue[rear];
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