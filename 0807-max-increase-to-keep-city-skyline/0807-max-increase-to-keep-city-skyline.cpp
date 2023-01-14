class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int nRow = grid.size(), nCol = grid[0].size();
        
        vector<vector<int>> maxHeights(nRow, vector<int>(nCol, 0));
        
        // Check for maximum-height for each column
        for(int row = 0; row < nRow; ++row) {
            int mxHeight = 0;
            for(int col = 0; col < nCol; ++col)
                mxHeight = max(mxHeight, grid[row][col]);
            
            for(int col = 0; col < nCol; ++col)
                maxHeights[row][col] = mxHeight;
        }
        
        // Check for maximum-height for each row
        for(int col = 0; col < nCol; ++col) {
            int mxHeight = 0;
            for(int row = 0; row < nRow; ++row)
                mxHeight = max(mxHeight, grid[row][col]);
            
            for(int row = 0; row < nRow; ++row)
                maxHeights[row][col] = min(maxHeights[row][col], mxHeight);
        }
        
        // Increment all the buildings as much as possible
        int maxPossibleHeightIncrease = 0;
        for(int row = 0; row < nRow; ++row) {
            for(int col = 0; col < nCol; ++col) {
                maxPossibleHeightIncrease += (maxHeights[row][col] - grid[row][col]);
            }
        }
        
        return maxPossibleHeightIncrease;
    }
};