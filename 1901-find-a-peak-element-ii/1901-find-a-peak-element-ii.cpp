class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int nRow = mat.size(), nCol = mat[0].size();
        int lowCol = 0, highCol = nCol-1;

        while(lowCol <= highCol) {
            int midCol = lowCol + (highCol - lowCol) / 2;

            int mxEle = INT_MIN, row = -1;
            for(int i = 0; i < nRow; ++i) {
                if(mat[i][midCol] > mxEle) {
                    mxEle = mat[i][midCol];
                    row = i;
                }
            }

            cout << lowCol << "," << highCol << " " << midCol << " - " << row << endl;
            
            if(midCol > 0  &&  mat[row][midCol-1] > mat[row][midCol]) {
                highCol = midCol - 1;
            } else if(midCol < nCol-1  &&  mat[row][midCol+1] > mat[row][midCol]) {
                lowCol = midCol + 1;
            } else {
                return {row, midCol};
            }
        }

        return {-1, -1};
    }
};