class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img)
    {
        int nRow = img.size(), nCol = img[0].size();
        
        vector<vector<int>> res(nRow, vector<int>(nCol, 0));
        for(int row = 0; row < nRow; ++row)
        {
            for(int col = 0; col < nCol; ++col)
            {
                int cnt = 0, sum = 0;
                
                // Top-Left
                if(row > 0  and  col > 0)
                {
                    sum += img[row-1][col-1];
                    ++cnt;
                }
                
                // Top
                if(row > 0)
                {
                    sum += img[row-1][col];
                    ++cnt;
                }
                
                // Top-Right
                if(row > 0  and  col < nCol-1)
                {
                    sum += img[row-1][col+1];
                    ++cnt;
                }
                
                // Right
                if(col < nCol-1)
                {
                    sum += img[row][col+1];
                    ++cnt;
                }
                
                // Bottom-Right
                if(row < nRow-1  and  col < nCol-1)
                {
                    sum += img[row+1][col+1];
                    ++cnt;
                }
                
                // Bottom
                if(row < nRow-1)
                {
                    sum += img[row+1][col];
                    ++cnt;
                }
                
                // Bottom-Left
                if(row < nRow-1  and  col > 0)
                {
                    sum += img[row+1][col-1];
                    ++cnt;
                }
                
                // Left
                if(col > 0)
                {
                    sum += img[row][col-1];
                    ++cnt;
                }
                
                // Itself
                sum += img[row][col];
                ++cnt;
                
                
                res[row][col] = sum / cnt;
            }
        }
        
        return res;
    }
};