class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nRow = matrix.size(), nCol = matrix[0].size();
        
        int colFlag = 1;
        
        for(int row = 0; row < nRow; ++row) {
            for(int col = 0; col < nCol; ++col) {
                if(matrix[row][col] == 0) {
                    // If its first col
                    // then we make use of 'colFlag'
                    if(col == 0) {
                        // Make first col flag = 0
                        colFlag = 0;
                        // Make first element in row = 0
                        // matrix[row][0] = 0;
                    }
                    else {
                        // Make first element in col = 0
                        matrix[0][col] = 0;
                        // Make first element in row = 0
                        matrix[row][0] = 0;
                    }
                }
            }
        }
        
        // Start from end of matrix to avoid problem
        // of initializing the flag area of matrix
        for(int row = nRow-1; row >= 0; --row) {
            for(int col = nCol-1; col >= 0; --col) {
                if(col == 0) {
                    // If row or 'colFlag' = 0
                    // then make the element 0
                    if(colFlag == 0  ||  matrix[row][0] == 0)
                        matrix[row][col] = 0;
                }
                else {
                    // If the row or col flag = 0
                    // then make the element 0
                    if(matrix[row][0] == 0  ||  matrix[0][col] == 0)
                        matrix[row][col] = 0;
                }
            }
        }
    }
};