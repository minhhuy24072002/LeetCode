class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> prefixSum(mat.size() + 1);
        vector<vector<int>> res(mat.size());
        int x1, x2, y1, y2;
        
        for (int i = 0; i < prefixSum.size(); i++) {
            prefixSum[i] = vector<int>(mat[0].size() + 1);
        }
        
        for (int i = 0; i < res.size(); i++) res[i] = vector<int>(mat[0].size());
        
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] + prefixSum[i + 1][j] - prefixSum[i][j] + mat[i][j]; 
            }
        }

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                x1 = max(i - k, 0);
                x2 = min(i + k, (int)(mat.size() - 1));
                y1 = max(j - k, 0);
                y2 = min(j + k, (int)(mat[0].size() - 1));
                //cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << endl;
                res[i][j] = prefixSum[x2 + 1][y2 + 1] - prefixSum[x1][y2 + 1] - prefixSum[x2 + 1][y1] + prefixSum[x1][y1];;
            }
        }
        
        return res;
    }
};