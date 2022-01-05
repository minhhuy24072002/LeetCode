class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        int res = nums[0];
        dp[0] = nums[0];
        
        if (nums.size() > 1) {
            dp[1] = nums[1];
            res = max(res, dp[1]);
        }
        
        if (nums.size() > 2) {
            dp[2] = nums[0] + nums[2];
            res = max(res, dp[2]);
        }
        
        for (int i = 3; i < nums.size(); i++) {
            dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
            res = max(res, dp[i]);
        }
        
        return res;
    }
};