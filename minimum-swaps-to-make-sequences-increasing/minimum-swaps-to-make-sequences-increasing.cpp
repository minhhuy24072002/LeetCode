class Solution {
public:
    int minSwap(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int dp0, dp1, new_dp0, new_dp1;
//         for (int i = 0; i < n; i++){
//             for (int j = 0; j < n; j++){
//                 dp[i][j] = 100001;
//             }
//         }
        
        dp0=0;
        dp1=1;
        
        for (int i=1;i<n;i++)
        {
            new_dp1 = 100001;
            new_dp0 = 100001;
            if (a[i]>a[i-1] && b[i]>b[i-1]) new_dp0=min(new_dp0,dp0);
            if (a[i]>b[i-1] && b[i]>a[i-1]) new_dp0=min(new_dp0,dp1);
            if (b[i]>a[i-1] && a[i]>b[i-1]) new_dp1=min(new_dp1,dp0+1);
            if (b[i]>b[i-1] && a[i]>a[i-1]) new_dp1=min(new_dp1,dp1+1);
            dp0 = new_dp0;
            dp1 = new_dp1;
            cout << new_dp0 << ' ' << new_dp1 << endl;
        }
        //cout << dp[n-1][0] << ' ' << dp[n-1][1] << endl;
        return min(dp0,dp1);
    }
};