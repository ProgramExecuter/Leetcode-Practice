class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) 
    {
        long sum = 0, sum2 = 0;
        int nRow = grid.size(), nCol = grid[0].size();
        int n = nRow * nCol;
        
        for(auto row : grid)
        {
            for(int num : row)
            {
                sum += num;
                sum2 += (1ll * num * num);
            }
        }
        
        // Subtract from actual nos should have been
        // X => missing number   Y => repeating number
        sum -= (1ll * n * (n + 1)) / 2;                     // Y - X
        sum2 -= (1ll * n * (n + 1) * (2 * n + 1)) / 6;      // Y^2 - X^2
                                                            // (Y - X) * (Y + X)
        
        // Y + X
        long tmp = sum2 / sum;
        
        int x = (tmp - sum) / 2;
        int y = (tmp + sum) / 2;
        
        // Repeating, Missing number
        return {y, x};
    }
};