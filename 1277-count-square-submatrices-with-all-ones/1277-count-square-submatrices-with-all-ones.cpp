class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int nRow = matrix.size(), nCol = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(nRow, vector<int>(nCol, 0));
        
        // Base case for the DP
        for(int row = 0; row < nRow; ++row)
            ans += (dp[row][0] = matrix[row][0]);
        
        for(int col = 1; col < nCol; ++col)
            ans += (dp[0][col] = matrix[0][col]);
        
        for(int row = 1; row < nRow; ++row) {
            for(int col = 1; col < nCol; ++col) {
                int left = dp[row][col-1], up = dp[row-1][col], diag = dp[row-1][col-1];
                
                // Calculate the no. of squares whose right-bottom
                // is the current square and it's   '1'
                if(matrix[row][col] == 1)
                    dp[row][col] = 1 + min(up, min(left, diag));
                else
                    dp[row][col] = 0; 
                
                // Add up no. of squares
                ans += dp[row][col];
            }
        }
        
        for(auto x : dp) {
            for(int i : x)
                cout << i << " ";
            cout << endl;
        }
        
        return ans;
    }
};