class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size());
        vector<int> dp2(nums.size());
        
        dp1[0] = nums[0];
        int res = dp1[0];
        
        for (int i = 1; i < nums.size() - 1; i++) {
            if (i == 1) dp1[i] = max(dp1[i - 1], nums[i]);
            else dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
            
            res = max(res, dp1[i]);
        }
        
        if (nums.size() > 1) {
            dp2[1] = nums[1];
            res = max(res, dp2[1]);
            
            for (int i = 2; i < nums.size(); i++) {
                if (i == 2) dp2[i] = max(dp2[i - 1], nums[i]);
                else dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
                
                res = max(res, dp2[i]);
            }
        }
        
        return res;
    }
};