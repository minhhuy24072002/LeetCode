class Solution {
public:
    bool check(int x, int y, int dx, int dy, int m, int n) {
        if (x + dx >= m) return false;
        if (x + dx < 0) return false;
        if (y + dy >= n) return false;
        if (y + dy < 0) return false;
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        map<pair<int, int>, int> mark;
        int res = 0, x, y;
        queue <pair<int, int>> gridQueue;
        const int dx[4] = {-1, 0, 0, 1};
        const int dy[4] = {0, -1, 1, 0};
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!mark[{i, j}] && grid[i][j] == '1') {
                    res++;
                    gridQueue.push({i, j});
                    
                    while (gridQueue.size()) {
                        x = gridQueue.front().first;
                        y = gridQueue.front().second;
                        mark[{x, y}] = 1;
                        gridQueue.pop();
                        
                        for (int dir = 0; dir < 4; dir++) {
                            if (check(x, y, dx[dir], dy[dir], grid.size(), grid[0].size())) {
                                if (grid[x + dx[dir]][y + dy[dir]] == '1' && !mark[{x + dx[dir], y + dy[dir]}]) {
                                    gridQueue.push({x + dx[dir], y + dy[dir]});
                                    mark[{x + dx[dir], y + dy[dir]}] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return res;
    }
};