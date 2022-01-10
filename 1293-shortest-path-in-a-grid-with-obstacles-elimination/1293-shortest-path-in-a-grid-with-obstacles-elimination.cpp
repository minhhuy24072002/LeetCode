class Solution {
public:
    bool check(int dx, int dy, int x, int y, int m, int n) {
        if (x + dx < 0) return false;
        if (x + dx >= m) return false;
        if (y + dy < 0) return false;
        if (y + dy >= n) return false;
        
        return true;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int visited[grid.size()][grid[0].size()][k + 1];
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                for (int t = 0; t <= k; t++) visited[i][j][t] = 0;
            }
        }
        
        queue<pair<int, pair<int, int>>> gridQueue;
        gridQueue.push({k, {0, 0}});
        int x, y, destroyLeft, res = -1;
        const int dx[4] = {-1, 0, 0, 1};
        const int dy[4] = {0, -1, 1, 0};
        
        while (gridQueue.size()) {
            x = gridQueue.front().second.first;
            y = gridQueue.front().second.second;
            destroyLeft = gridQueue.front().first;
            gridQueue.pop();
            //cout << x << ' ' << y << ' ' << destroyLeft << ' ' << visited[x][y][destroyLeft] << endl;
            
            if (x == grid.size() - 1 && y == grid[0].size() - 1) {
                res = visited[x][y][destroyLeft];
                break;
            }
            
            for (int i = 0; i < 4; i++)
                if (check(dx[i], dy[i], x, y, grid.size(), grid[0].size())) {
                    if (grid[x + dx[i]][y + dy[i]] == 0 && !visited[x + dx[i]][y + dy[i]][destroyLeft]) {
                        visited[x + dx[i]][y + dy[i]][destroyLeft] = visited[x][y][destroyLeft] + 1;
                        gridQueue.push({destroyLeft, {x + dx[i], y + dy[i]}});
                    } else if (grid[x + dx[i]][y + dy[i]] == 1 && destroyLeft > 0 && !visited[x + dx[i]][y + dy[i]][destroyLeft - 1]) {
                        visited[x + dx[i]][y + dy[i]][destroyLeft - 1] = visited[x][y][destroyLeft] + 1;
                        gridQueue.push({destroyLeft - 1, {x + dx[i], y + dy[i]}});
                    }
                }
        }
        
        return res;
    }
};