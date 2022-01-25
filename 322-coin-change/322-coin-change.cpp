class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<long long> dp(amount + 1);
        
        for (int i = 0; i <= amount; i++) dp[i] = -1;
        dp[0] = 0;

        for (int i = coins.size() - 1; i > -1; i--) {
            for (int sum = 0; sum <= amount; sum++) {
                if (sum - coins[i] >= 0 && dp[sum - coins[i]] != -1)
                    if (dp[sum] >= 0)
                        dp[sum] = min(dp[sum], dp[sum - coins[i]] + 1);
                    else dp[sum] = dp[sum - coins[i]] + 1;
            }
        }
        
        return dp[amount];
    }
};