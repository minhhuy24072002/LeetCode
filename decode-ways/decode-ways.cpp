class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length());
        int temp;
        if (s[0] == '0') return 0;
        
        dp[0] = 1;
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] > '0')
                dp[i] += dp[i - 1];
            if (s[i - 1] != '0') {
                temp = (s[i] - '0') + (s[i - 1] - '0') * 10;
                if (temp <= 26 && temp > 0) {
                    if (i > 1) dp[i] += dp[i - 2];
                    else dp[i]++;
                }
            }
        }
        
        return dp[s.length() - 1];
    }
};