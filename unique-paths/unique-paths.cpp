class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m);
        
        for (int i = 0; i < m; i++) dp[i] = vector<int>(n);
        dp[0][0] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 > -1) dp[i][j] += dp[i - 1][j];
                if (j - 1 > -1) dp[i][j] += dp[i][j - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};