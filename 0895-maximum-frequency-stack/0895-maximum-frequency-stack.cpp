class FreqStack {
public:
    map<int, stack<int>> fStack;
    unordered_map<int, int> freq;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        fStack[freq[val]].push(val);
    }
    
    int pop() {
        map<int, stack<int>>::iterator maxFreqElement;
        maxFreqElement = fStack.end();
        maxFreqElement--;
        if (maxFreqElement->second.size() == 0) {
            fStack.erase(maxFreqElement);
            maxFreqElement--;
        }
        int result = maxFreqElement->second.top();
        freq[result]--;
        maxFreqElement->second.pop();
        return result;
    }
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */