class Solution {
public:
    void util(int &row, int &col, int &nRow, int &nCol, vector<vector<int>> &mat) {
        int tmpR = row, tmpC = col, idx = 0;
        vector<int> tmp;

        // Check while we're not out-of-bounds
        while(tmpR < nRow  and  tmpC < nCol)
            tmp.push_back(mat[tmpR++][tmpC++]);

        sort(tmp.begin(), tmp.end());

        tmpR = row, tmpC = col;
        while(tmpR < nRow  and  tmpC < nCol)
            mat[tmpR++][tmpC++] = tmp[idx++];
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int nRow = mat.size(), nCol = mat[0].size();
        
        // Check for all starting point at 0-column
        for(int row = 0, col = 0; row < nRow; ++row)
            util(row, col, nRow, nCol, mat);
        
        // Check for all starting point at 0-row, except 0-column
        for(int col = 1, row = 0; col < nCol; ++col)
            util(row, col, nRow, nCol, mat);
        
        return mat;
    }
};