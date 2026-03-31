class Solution {
public:
    void setNewDir(int &i, int &j, int &minRow, int &maxRow, int &minCol, int &maxCol) {
        if(i==-1 && j==0) {         // PrevDir = up,  NewDir = right
            i = 0;  j = 1;
            ++minCol;
        } else if(i==0 && j==1) {   // PrevDir = right,  NewDir = down
            i = 1; j = 0;
            ++minRow;
        } else if(i==1 && j==0) {   // PrevDir = down,  NewDir = left
            i = 0; j = -1;
            --maxCol;
        } else {                    // PrevDir = left,  NewDir = up
            i = -1; j = 0;
            --maxRow;
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int minRow = 0, minCol = 0, maxRow = m-1, maxCol = n-1;
        int i = 0, j = 0;       // Starting Index

        // Current Direction
        int di = 0, dj = 1;       // Left starting direction

        while(i >= minRow && i <= maxRow && j >= minCol && j <= maxCol) {
            res.push_back(matrix[i][j]);

            // Out of bounds
            if(i+di < minRow || i+di > maxRow || j+dj < minCol || j+dj > maxCol) {
                // Change direction
                setNewDir(di, dj, minRow, maxRow, minCol, maxCol);
            }

            i += di;    j += dj;
        }

        return res;
    }
};