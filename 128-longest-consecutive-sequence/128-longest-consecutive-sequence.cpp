class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> status;
        int count, res = 0;
        
        for (int i = 0; i < nums.size(); i++) status[nums[i]] = 1;
        
        for (int i = 0; i < nums.size(); i++) 
            if (status[nums[i]] != 2) {
                if (status[nums[i] - 1] == 0) {
                    count = 0;
                    int num = nums[i];
                    while (status[num] == 1) {
                        count++;
                        status[num] = 2;
                        num++;
                    }
                
                    res = max(res, count);
                }
            }
        
        return res;
    }
};