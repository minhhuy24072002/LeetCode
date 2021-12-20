class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, res = -1e4 - 1;
        
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            res = max(res, currSum);
            
            if (currSum < 0) currSum = 0;
        }
        
        return res;
    }
};