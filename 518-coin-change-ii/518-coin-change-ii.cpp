class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int value = 1; value <= amount; value++) {
                if (value - coins[i] >= 0) {
                    dp[value] += dp[value - coins[i]];
                }
            }
        }
        return dp[amount];
    }
};