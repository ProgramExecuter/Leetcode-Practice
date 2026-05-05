class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nRow = matrix.size(), nCol = matrix[0].size();
        int currRow = 0, currCol = nCol-1;
        int low = 0, high = nRow-1, mid = 0, tmpRes = -1;

        while(1) {
            low = 0;    high = currCol;     tmpRes = -1;
            // Find the element in current row, which is <= target
            while(low <= high) {
                mid = low + (high - low) / 2;
                if(matrix[currRow][mid] == target)
                    return true;
                else if(matrix[currRow][mid] > target) {
                    high = mid - 1;
                } else {
                    tmpRes = mid;
                    low = mid + 1;
                }
            }
            if(tmpRes == -1)       return false;
            currCol = tmpRes;

            tmpRes = -1;   low = currRow;    high = nRow - 1;
            // Find the current column's element, which is >= target
            while(low <= high) {
                mid = low + (high - low) / 2;

                if(matrix[mid][currCol] == target)
                    return true;
                else if(matrix[mid][currCol] > target) {
                    tmpRes =  mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if(tmpRes == -1)        return false;
            currRow = tmpRes;
        }

        return false;
    }
};