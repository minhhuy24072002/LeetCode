class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length() + 1);
        int res = 0;
        
        for (int i = 0; i < dp.size(); i++) dp[i] = vector<int>(text2.length() + 1);
        
        for (int i = 0; i < text1.length(); i++) {
            for (int j = 0; j < text2.length(); j++) {
                if (text1[i] == text2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                
                res = max(res, dp[i + 1][j + 1]);
            }
        }
        
        return res;
    }
};