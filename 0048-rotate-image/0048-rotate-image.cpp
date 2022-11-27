class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        
        // Take TRANSPOSE of matrix
        for(int i=0; i<len; ++i) {
            for(int j=0; j<i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse each row
        for(int i=0; i<len; ++i) {
            // Use two pointer
            for(int j=0; j<len/2; ++j) {
                swap(matrix[i][j], matrix[i][len-1-j]);
            }
        }
    }
};