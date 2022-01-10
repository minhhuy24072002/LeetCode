class Solution {
public:
    void initializeDp(vector<vector<int>> & dp, int size) {
        for (int i = 0; i < dp.size(); i++) dp[i] = vector<int>(size);
    }
    int longestLine(vector<vector<int>>& mat) {
        vector<vector<int>> horDp(mat.size());
        vector<vector<int>> verDp(mat.size());
        vector<vector<int>> diagDp(mat.size());
        vector<vector<int>> antiDiagDp(mat.size());
        int res = 0;
        
        initializeDp(horDp, mat[0].size());
        initializeDp(verDp, mat[0].size());
        initializeDp(diagDp, mat[0].size());
        initializeDp(antiDiagDp, mat[0].size());
        
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    horDp[i][j] = 1;
                    verDp[i][j] = 1;
                    diagDp[i][j] = 1;
                }
                
                if (i > 0 && mat[i][j] == 1 && mat[i - 1][j] == 1) verDp[i][j] = verDp[i - 1][j] + 1;
                
                if (j > 0 && mat[i][j] == 1 && mat[i][j - 1] == 1) horDp[i][j] = horDp[i][j - 1] + 1;
                
                if (i > 0 && j > 0 && mat[i][j] == 1 && mat[i - 1][j - 1] == 1) diagDp[i][j] = diagDp[i - 1][j - 1] + 1;
                
                res = max(res, max(horDp[i][j], max(verDp[i][j], diagDp[i][j])));
            } 
        }
        
        for (int i = mat.size() - 1; i > -1; i--) {
            for (int j = mat[0].size() - 1; j > -1; j--) {
                if (mat[i][j] == 1) antiDiagDp[i][j] = 1;
                
                if (i < mat.size() - 1 && j > 0 && mat[i][j] == 1 && mat[i + 1][j - 1] == 1) antiDiagDp[i][j] = antiDiagDp[i + 1][j - 1] + 1;
                
                res = max(res, antiDiagDp[i][j]);
            }
        }

        return res;
    }
};