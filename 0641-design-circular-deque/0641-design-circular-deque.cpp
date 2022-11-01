class MyCircularDeque {
public:
    int capacity;
    int currentSize;
    int front;
    int rear;
    vector<int> myDeque;
    
    MyCircularDeque(int k) {
        capacity = k;
        currentSize = 0;
        front = 0;
        rear = k - 1;
        myDeque = vector<int>(k);
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        
        front = (front - 1 + capacity) % capacity;
        myDeque[front] = value;
        currentSize++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        
        rear = (rear + 1) % capacity;
        myDeque[rear] = value;
        currentSize++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        
        front = (front + 1) % capacity;
        currentSize--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        
        rear = (rear - 1 + capacity) % capacity;
        currentSize--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        
        return myDeque[front];
    }
    
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        
        return myDeque[rear];
    }
    
    bool isEmpty() {
        return currentSize == 0;
    }
    
    bool isFull() {
        return currentSize == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */