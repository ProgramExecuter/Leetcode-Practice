class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 'dirArr' for directions row,col additions
        vector<pair<int,int>> dirArr({{0,1},{1,0},{0,-1},{-1,0}});
        vector<int> ans;
        
        int nRow = matrix.size(), nCol = matrix[0].size();
        // Starting point and direction
        int rowSt = 0, rowEn = nRow-1, colSt = 0, colEn = nCol-1;
        int row = 0, col = 0, dir = 0;
        
        while(rowSt <= rowEn  &&  colSt <= colEn) {
            dir %= 4;
            
            // Loop in the given direction
            while(1) {
                ans.push_back(matrix[row][col]);
                
                int nxtRow = row + dirArr[dir].first;
                int nxtCol = col + dirArr[dir].second;
                
                // If we cannot move to next (row, col), then end this
                if(nxtRow<rowSt || nxtRow>rowEn || nxtCol<colSt || nxtCol>colEn) {
                    break;
                }
                // Else move to next grid
                else {
                    row = nxtRow;       col = nxtCol;
                }
            }

            // Shrink and move according to direction
            if(dir == 0) {
                ++row;  ++rowSt;
            }
            else if(dir == 1) {
                --col;  --colEn;
            }
            else if(dir == 2) {
                --row;  --rowEn;
            }
            else {
                ++col;  ++colSt;
            }
            
            // Move to next direction
            ++dir;
        }
        
        return ans;
    }
};