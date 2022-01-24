class Solution {
public:
    int used[10];
    vector<vector<int>> res;
    
    void recursion(int index, int currSum, vector<int>& currCombination, int k, int n) {
        if (index >= k) {
            if (currSum == n) res.push_back(currCombination);
            return;
        }
        
        for (int i = 1; i < 10; i++)
            if (!used[i] && (currCombination.size() == 0 || currCombination[currCombination.size() - 1] < i)) {
                used[i] = true;
                currCombination.push_back(i);
                recursion(index + 1, currSum + i, currCombination, k, n);
                used[i] = false;
                currCombination.pop_back();
            }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> currCombination;
        recursion(0, 0, currCombination, k, n);
        
        return res;
    }
};