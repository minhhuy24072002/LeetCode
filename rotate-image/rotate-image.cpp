class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int xRight = 0, yRight = 0, xLeft = matrix.size() - 1, yLeft = matrix.size() - 1, temp, prevGrid, x, y, difference;
        
        while (xRight < xLeft) {
            difference = xLeft - xRight;
            while (difference--) {
                x = xRight;
                y = yRight;
            
                prevGrid = matrix[x][y];
                while (y < yLeft) {
                    y++;
                    temp = matrix[x][y];
                    matrix[x][y] = prevGrid;
                    prevGrid = temp;
                }
            
                while (x < xLeft) {
                    x++;
                    temp = matrix[x][y];
                    matrix[x][y] = prevGrid;
                    prevGrid = temp;
                }
            
                while (y > yRight) {
                    y--;
                    temp = matrix[x][y];
                    matrix[x][y] = prevGrid;
                    prevGrid = temp;
                }
            
                while (x > xRight) {
                    x--;
                    temp = matrix[x][y];
                    matrix[x][y] = prevGrid;
                    prevGrid = temp;
                }
            }
            
            xRight++;
            yRight++;
            xLeft--;
            yLeft--;
        }
    }
};