class Solution {
public:
    bool check(int x, int y, int dx, int dy, int m, int n) {
        if (x + dx >= m) return false;
        if (x + dx < 0) return false;
        if (y + dy >= n) return false;
        if (y + dy < 0) return false;
        return true;
    }
    bool isExist(int x, int y, int currLength, vector<vector<char>> &board, string word) {
        if (currLength >= word.length()) return true;
        const int dx[4] = {-1, 0, 0, 1};
        const int dy[4] = {0, -1, 1, 0};
        bool isRes = false;
        board[x][y] = '#';
        
        for (int i = 0; i < 4; i++)
            if (check(x, y, dx[i], dy[i], board.size(), board[0].size()))
                if (board[x + dx[i]][y + dy[i]] == word[currLength]) {
                    isRes |= isExist(x + dx[i], y + dy[i], currLength + 1, board, word);
                    if (isRes) break;
                }
        
         board[x][y] = word[currLength - 1];
         return isRes;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0])
                    if (isExist(i, j, 1, board, word)) return true;
            }
        }
        
        return false;
    }
};