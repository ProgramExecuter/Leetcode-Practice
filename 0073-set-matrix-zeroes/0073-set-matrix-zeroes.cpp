class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nRows = matrix.size(), nCols = matrix[0].size();
        
        // 2 arrays
        vector<bool> horizontalZero(nCols, false), verticalZero(nRows, false);
        
        for(int row = 0; row < nRows; ++row)
        {
            for(int col = 0; col < nCols; ++col)
            {
                // Set corresponding flag to zero
                if(matrix[row][col] == 0)
                {
                    horizontalZero[col] = true;
                    verticalZero[row] = true;
                }
            }
        }
        
        for(int row = 0; row < nRows; ++row)
        {
            for(int col = 0; col < nCols; ++col)
            {
                if(horizontalZero[col]  or  verticalZero[row])
                    matrix[row][col] = 0;
            }
        }
    }
};