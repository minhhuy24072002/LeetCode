class Solution {
public:
    bool check(int x, int y, int dx, int dy, int m, int n) {
        if (x + dx >= m) return false;
        if (x + dx < 0) return false;
        if (y + dy >= n) return false;
        if (y + dy < 0) return false;
        
        return true;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        const int dx[4] = {-1, 0, 0, 1};
        const int dy[4] = {0, -1, 1, 0};
        queue<pair<int, pair<int, int>>> gridQueue;
        int prevDirection, x, y;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) gridQueue.push({-1, {i, j}});
            }
        }
        
        while (gridQueue.size()) {
            x = gridQueue.front().second.first;
            y = gridQueue.front().second.second;
            matrix[x][y] = 0;
            prevDirection = gridQueue.front().first;
            gridQueue.pop();
            
            if (prevDirection == -1) {
                for (int direction = 0; direction < 4; direction++) {
                    if (check(x, y, dx[direction], dy[direction], matrix.size(), matrix[0].size()))
                        gridQueue.push({direction, {x + dx[direction], y + dy[direction]}});
                }
            } else if (check(x, y, dx[prevDirection], dy[prevDirection], matrix.size(), matrix[0].size()))
                gridQueue.push({prevDirection, {x + dx[prevDirection], y + dy[prevDirection]}});
        }
    }
};