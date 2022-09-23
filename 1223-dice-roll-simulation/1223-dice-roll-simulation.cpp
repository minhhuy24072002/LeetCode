class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        long long mod = 1e9 + 7;
        int res = 0;
        vector<vector<vector<long long>>> dp(n);
        for (int i = 0; i < dp.size(); i++) {
            dp[i] = vector<vector<long long>>(6);
        }
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < 6; j++) {
                dp[i][j] = vector<long long>(16);
            }
        }
        
        for (int j = 0; j < 6; j++) {
            dp[0][j][1] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int num = 0; num < 6; num++) {
                for (int times = 1; times <= 15; times++) {
                    if (times > rollMax[num]) break;
                    if (times == 1) {
                        for (int rolledNum = 0; rolledNum < 6; rolledNum++) {
                            if (rolledNum == num) continue;
                            for (int prevTimes = 1; prevTimes <= 15; prevTimes++) {
                                dp[i][num][times] = ((dp[i][num][times] % mod) + (dp[i - 1][rolledNum][prevTimes] % mod) % mod);
                            }
                        }
                    } else {
                        dp[i][num][times] = ((dp[i][num][times] % mod) + (dp[i - 1][num][times - 1] % mod)) % mod;
                    }
                }
            }
        }
        cout << 1;
        for (int num = 0; num < 6; num++) {
            for (int times = 1; times <= 15; times++) {
                res = ((res % mod) + (dp[n - 1][num][times] % mod) % mod);
            }
        }
        return res;
    }
};

//dp[n][m][k] += dp[n - 1][1 -> 6 <> m][k] + dp[n - 1][m][0 -> k - 1]