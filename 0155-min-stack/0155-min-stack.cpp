class MinStack {
public:
    stack<int> actualStack, minStack;
    
    MinStack() {
        
    }
    
    void push(int val) {
        int currentMin;
        if (actualStack.size() == 0) {
            currentMin = INT_MAX;
        } else {
            currentMin = minStack.top();
        }
        actualStack.push(val);
        minStack.push(min(currentMin, val));
    }
    
    void pop() {
        actualStack.pop();
        minStack.pop();
    }
    
    int top() {
        return actualStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */