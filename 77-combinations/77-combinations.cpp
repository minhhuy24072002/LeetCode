class Solution {
public:
    vector<vector<int>> res;
    
    void recursion(int index, vector<int>& bitSet, int n, int k, int count1s) {
        if (index > n) {
            if (count1s != k) return;
            vector<int> temp;
            for (int i = 1; i <= n; i++)
                if (bitSet[i] == 1) temp.push_back(i);
            res.push_back(temp);
            return;
        }
        
        if (count1s > k) return;
        
        for (int i = 0; i < 2; i++) {
            bitSet[index] = i;
            recursion(index + 1, bitSet, n, k, count1s + i);
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> bitSet(n + 1);
        
        recursion(1, bitSet, n, k, 0);
        
        return res;
    }
};