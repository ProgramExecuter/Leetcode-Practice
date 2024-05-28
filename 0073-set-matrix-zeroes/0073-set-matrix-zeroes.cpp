class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nRows = matrix.size(), nCols = matrix[0].size();
        bool row0 = true;
        
        for(int row = 0; row < nRows; ++row)
        {
            for(int col = 0; col < nCols; ++col)
            {
                if(matrix[row][col] != 0)
                    continue;
                
                // Make row 0
                if(row == 0)
                    row0 = false;
                else
                    matrix[row][0] = 0;
                
                // Make column 0
                matrix[0][col] = 0;
            }
        }
        
        for(int row = 0; row < nRows; ++row)
        {
            for(int col = 0; col < nCols; ++col)
                cout << matrix[row][col];
            cout << endl;
        }
        
        for(int row = nRows-1; row >= 0; --row)
        {
            for(int col = nCols-1; col >= 0; --col)
            {   
                if(row == 0)
                {
                    if(row0 == false  ||  matrix[0][col] == 0)
                        matrix[row][col] = 0;
                }
                else
                {
                    if(matrix[row][0] == 0  ||  matrix[0][col] == 0)
                        matrix[row][col] = 0;
                }
            }
        }
    }
};