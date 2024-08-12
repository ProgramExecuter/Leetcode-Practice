class Solution {
public:
    bool isValidCell(int row, int col, int &nRows, int &nCols)
    {
        if(
            ( row >= 0  &&  row < nRows ) &&
            ( col >= 0  &&  col < nCols )
        )
            return true;
        return false;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> res;
        
        int maxDist = max(max(cStart, cols - cStart), max(rStart, rows - rStart));
        int currRow = rStart, currCol = cStart;
        res.push_back({rStart, cStart});
        
        int diff = 1;
        while(res.size() < rows * cols)
        {
            // 1    Right
            for(int i = 0; i < diff; ++i)
            {
                currRow += 0;       currCol += 1;
                if(isValidCell(currRow, currCol, rows, cols))
                    res.push_back({currRow, currCol});
            }
            
            // 1    Down
            for(int i = 0; i < diff; ++i)
            {
                currRow += 1;       currCol += 0;
                if(isValidCell(currRow, currCol, rows, cols))
                    res.push_back({currRow, currCol});
            }
            
            ++diff;
            
            // 2    Left
            for(int i = 0; i < diff; ++i)
            {
                currRow += 0;       currCol += -1;
                if(isValidCell(currRow, currCol, rows, cols))
                    res.push_back({currRow, currCol});
            }
            
            // 2    Up
            for(int i = 0; i < diff; ++i)
            {
                currRow += -1;       currCol += 0;
                if(isValidCell(currRow, currCol, rows, cols))
                    res.push_back({currRow, currCol});
            }
            
            ++diff;
        }
        
        return res;
    }
};