class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int nRows = matrix.size(), nCols = matrix[0].size();
        int low = 0, high = nRows - 1, mid = 0, foundRow = -1, foundCol = -1;

        while(low <= high) {
            mid = low + (high - low) / 2;

            if(matrix[mid][0] <= target) {
                foundRow = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if(foundRow == -1  ||  matrix[foundRow][0] > target)
            return false;

        low = 0;    high = nCols - 1;
        while(low <= high) {
            mid = low + (high - low) / 2;

            if(matrix[foundRow][mid] <= target) {
                foundCol = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if(foundCol == -1  ||  matrix[foundRow][foundCol] != target)
            return false;
        return true;
    }
};