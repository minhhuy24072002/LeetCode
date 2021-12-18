class Solution {
public:
    bool check(int x, int y, int dx, int dy, int m, int n) {
        if (x + dx < 0) return false;
        if (x + dx >= m) return false;
        if (y + dy < 0) return false;
        if (y + dy >= n) return false;
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        const int dx[4] = {-1, 0, 0, 1};
        const int dy[4] = {0, -1, 1, 0};
        int res = 0, x, y;
        
        map<pair<int,int>,int> mark;
        
        queue<pair<int,int>> qu;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !mark[make_pair(i,j)]) {
                    res++;
                    
                    qu.push(make_pair(i,j));
                    while (qu.size()) {
                        x = qu.front().first;
                        y = qu.front().second;
                        mark[make_pair(x,y)] = 1;
                        qu.pop();
                        
                        for (int direction = 0; direction < 4; direction++) {
                            if (check(x, y, dx[direction], dy[direction], grid.size(), grid[0].size())) {
                                if (grid[x + dx[direction]][y + dy[direction]] == '1' && !mark[make_pair(x + dx[direction], y + dy[direction])]) {
                                    qu.push(make_pair(x + dx[direction], y + dy[direction]));
                                    mark[make_pair(x + dx[direction], y + dy[direction])] = 1;
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