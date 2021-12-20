class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        unordered_map <int, int> count;
        vector<vector<int>> res;
        
        map <pair<int, int>, int> mark;
        int occurTimes;
        
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                if (count[-nums[i] - nums[j]] && !mark[{nums[i], nums[j]}] && -nums[i] - nums[j] >= nums[j]) {
                    occurTimes = 0;
                    if (nums[i] == -nums[i] - nums[j]) occurTimes++;
                    if (nums[j] == -nums[i] - nums[j]) occurTimes++;
                    
                    if (count[-nums[i] - nums[j]] - occurTimes > 0) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(-nums[i] - nums[j]);
                        
                        if (!mark[{temp[0],temp[1]}]) {
                            res.push_back(temp);
                            mark[{temp[0],temp[1]}] = 1;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};