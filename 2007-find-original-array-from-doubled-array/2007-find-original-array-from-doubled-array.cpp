class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int, int> count;
        vector<int> res;
        
        if (changed.size() % 2 != 0) return res;
        
        sort(changed.begin(), changed.end());
        for (int i = 0; i < changed.size(); i++) count[changed[i]]++;
        
        for (int i = 0; i < changed.size(); i++) {
            if (changed[i] != 0 && count[changed[i]] > 0 && count[changed[i] * 2] > 0) {
                res.push_back(changed[i]);
                count[changed[i]]--;
                count[changed[i] * 2]--;
            } else if (changed[i] == 0  && count[changed[i]] > 1) {
                res.push_back(changed[i]);
                count[changed[i]]--;
                count[changed[i] * 2]--;
            }
        }
        
        if (res.size() != changed.size() / 2) return vector<int>();
        return res;
    }
};