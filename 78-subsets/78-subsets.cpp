class Solution {
public:
    vector<vector<int>> res;
    
    void recursion(int index, vector<int>& nums, vector<int>& bitSet) {
        if (index >= nums.size()) {
            vector<int> temp;
            for (int i = 0; i < nums.size(); i++)
                if (bitSet[i] == 1) temp.push_back(nums[i]);
            res.push_back(temp);
            return;
        }
        
        for (int i = 0; i < 2; i++) {
            bitSet[index] = i;
            recursion(index + 1, nums, bitSet);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> bitSet(nums.size());
        
        recursion(0, nums, bitSet);
        
        return res;
    }
};