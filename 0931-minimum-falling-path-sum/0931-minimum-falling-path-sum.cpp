class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int nRows = matrix.size(), nCols = matrix[0].size();
        
        // Base Case, copy the value of top row to 'prev'
        vector<int> prev(nCols, 0);
        for(int i = 0; i < nCols; ++i)
            prev[i] = matrix[0][i];
        
        
        for(int row = 1; row < nRows; ++row) {
            vector<int> curr(nCols, 0);
            for(int col = 0; col < nCols; ++col) {
                // Up-Left
                int upLeft = col == 0 ? 1e8 : prev[col-1];
                
                // Up
                int up = prev[col];
                
                // Up-Right
                int upRight = col == nCols-1 ? 1e8 : prev[col+1];
                
                // Take the minimum of upper paths, and add the current matrix-element
                curr[col] = matrix[row][col] + min(up, min(upLeft, upRight));
            }
            prev = curr;
        }
        
        // Find the path with minimum sum
        int mnSumPath = 1e8;
        for(int x : prev)
            mnSumPath = min(mnSumPath, x);
        
        return mnSumPath;
    }
};