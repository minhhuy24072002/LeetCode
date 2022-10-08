class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size());
        vector<int> maxProfit(k * 2 + 1, -1e9);
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            dp[i] = vector<int>(k * 2 + 1, -1e9);
        }
        for (int i = 0; i < prices.size(); i++) {
            dp[i][1] = -prices[i];
            maxProfit[1] = max(maxProfit[1], dp[i][1]);
            for (int t = 2; t <= k * 2; t++) {
                if (t % 2 == 0) {
                    dp[i][t] = max(maxProfit[t - 1] + prices[i], dp[i][t]);
                    res = max(res, dp[i][t]);
                    maxProfit[t] = max(maxProfit[t], dp[i][t]);
                } else {
                    dp[i][t] = max(maxProfit[t - 1] - prices[i], dp[i][t]);
                    maxProfit[t] = max(maxProfit[t], dp[i][t]);          
                }
            }
        }
        return res;
    }
};