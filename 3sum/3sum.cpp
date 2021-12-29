class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> count;
        map<pair<int, pair<int, int>>, int> mark;
        vector<vector<int>> res;
        int size = nums.size(), duplicateTimes;
        
        if (nums.size() == 0) return res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) count[nums[i]]++;
        
        for (int i = 0; i < size - 2; i++) {
            for (int j = i + 1; j < size - 1; j++) {
                if (- nums[i] - nums[j] >= nums[j]) {
                    duplicateTimes = 0;
                    
                    if (nums[i] == - nums[i] - nums[j]) duplicateTimes++;
                    if (nums[j] == - nums[i] - nums[j]) duplicateTimes++;
                    if (count[- nums[i] - nums[j]] > duplicateTimes) 
                        if (!mark[{nums[i], {nums[j], - nums[i] - nums[j]}}]) {
                        res.push_back(vector<int>{nums[i], nums[j], - nums[i] - nums[j]});
                        mark[{nums[i], {nums[j], - nums[i] - nums[j]}}] = 1;
                    }
                }
            }
        }
        
        
        
        return res;
    }
};