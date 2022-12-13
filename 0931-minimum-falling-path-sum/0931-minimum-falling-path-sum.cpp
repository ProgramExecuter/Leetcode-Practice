class Solution {
public:
    int f(int row, int col, vector<vector<int>>& matrix, int &nRows, int &nCols, vector<vector<int>> &dp) {
        if(row >= nCols or col >= nCols or col < 0)
            return 1e8;
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        // Down-Left
        int downLeft = f(row+1, col-1, matrix, nRows, nCols, dp);
        
        // Down
        int down = f(row+1, col, matrix, nRows, nCols, dp);
        
        // Down-Right
        int downRight = f(row+1, col+1, matrix, nRows, nCols, dp);
        
        int downPaths = min(down, min(downLeft, downRight));
        if(downPaths == 1e8)
            downPaths = 0;
        
        return dp[row][col] = matrix[row][col] + downPaths;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int nRows = matrix.size(), nCols = matrix[0].size();
        
        vector<vector<int>> dp(nRows, vector<int>(nCols, -1));
        int mnSum = 1e8;
        
        for(int i = 0; i < nCols; ++i) {
            mnSum = min(mnSum, f(0, i, matrix, nRows, nCols, dp));
        }
        
        return mnSum;
    }
};