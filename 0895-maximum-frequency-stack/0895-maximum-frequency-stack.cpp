class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, list<int>> freqList;
    int maxFreq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(freq[val], maxFreq);
        freqList[freq[val]].push_back(val);
    }
    
    int pop() {
        int result = freqList[maxFreq].back();
        freqList[maxFreq].pop_back();
        freq[result]--;
        if (freqList[maxFreq].size() == 0) {
            maxFreq--;
        }
        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */