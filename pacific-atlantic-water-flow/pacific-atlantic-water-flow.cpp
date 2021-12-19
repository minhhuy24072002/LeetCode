class Solution {
public:
    bool check(int x, int y, int dx, int dy, int m, int n){
        if (x + dx >= m) return false;
        if (x + dx < 0) return false;
        if (y + dy >= n) return false;
        if (y + dy < 0) return false;
        return true;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int dx[4] = {-1, 0, 0, 1};
        const int dy[4] = {0, -1, 1, 0};
        bool isHighest;
        vector<vector<int>> res;
        queue <pair<int,int>> gridQueue;
        map <pair<int,int>, int> pacificMark;
        map <pair<int,int>, int> atlanticMark;
        
        for (int i = 0; i < heights.size(); i++) {
            pacificMark[make_pair(i, 0)] = 1;
            gridQueue.push(make_pair(i, 0));
        }
        for (int j = 0; j < heights[0].size(); j++) {
            pacificMark[make_pair(0, j)] = 1;
            gridQueue.push(make_pair(0, j));
        }
        
        for (int i = 0; i < heights.size(); i++) {
            atlanticMark[make_pair(i, heights[0].size() - 1)] = 1;
            gridQueue.push(make_pair(i, heights[0].size() - 1));
        }
        for (int j = 0; j < heights[0].size(); j++) {
            atlanticMark[make_pair(heights.size() - 1, j)] = 1;
            gridQueue.push(make_pair(heights.size() - 1, j));
        }
        
        int x, y;
        while (gridQueue.size()) {
            x = gridQueue.front().first;
            y = gridQueue.front().second;
            gridQueue.pop();
            
            for (int direction = 0; direction < 4; direction++) {
                if (check(x, y, dx[direction], dy[direction], heights.size(), heights[0].size())) {
                    if (heights[x + dx[direction]][y + dy[direction]] >= heights[x][y]) {
                        if (!pacificMark[make_pair(x + dx[direction],y + dy[direction])] && pacificMark[make_pair(x, y)] == 1) {
                            pacificMark[make_pair(x + dx[direction],y + dy[direction])] = 1;
                            gridQueue.push(make_pair(x + dx[direction], y + dy[direction]));
                        }
                    
                        if (!atlanticMark[make_pair(x + dx[direction],y + dy[direction])] && atlanticMark[make_pair(x, y)] == 1) {
                            atlanticMark[make_pair(x + dx[direction],y + dy[direction])] = 1;
                            gridQueue.push(make_pair(x + dx[direction], y + dy[direction]));
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++)
                if (atlanticMark[make_pair(i,j)] == 1 && pacificMark[make_pair(i,j)] == 1) res.push_back(vector<int> {i,j});
        }
        
        return res;
    }
};