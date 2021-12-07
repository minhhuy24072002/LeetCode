class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int *dp = new int[target + 1] {};
        const int kMaxInt = (1 << 31) - 1;
        dp[target] = 1;
        
        sort(nums.begin(), nums.end());
        
        for (int i = target; i > 0; --i) {
            if (!dp[i]) continue;
            
            for (int& num: nums) {
			    // HACK: we just ignore very big numbers: dp[i - num] > kMaxInt - dp[i]
                if (i < num || dp[i - num] > kMaxInt - dp[i]) break;
                dp[i - num] += dp[i];
            }
        }
        
		// Let's be polite and always clean after ourselves or use vector instead
		int res = dp[0];
		delete [] dp;
		
        return res;
    }
};