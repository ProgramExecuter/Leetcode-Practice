class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>> &visited, int row, int col) {
        // Reached end of area or end of current island
        if(
            row >= grid.size()  or  col >= grid[0].size()  or
            col < 0  or  row < 0  or  grid[row][col] == '0'  or
            visited[row][col]
        )
            return;
        
        // Mark this grid as visited
        visited[row][col] = true;
        
        // DFS traversal for right, down, up and left
        dfs(grid, visited, row, col+1);
        dfs(grid, visited, row+1, col);
        dfs(grid, visited, row-1, col);
        dfs(grid, visited, row, col-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int nRow = grid.size(), nCol = grid[0].size(), noOfIslands = 0;
        vector<vector<bool>> visited(nRow, vector<bool>(nCol, false));
        
        // Iterate for each grid
        for(int row = 0; row < nRow; ++row) {
            for(int col = 0; col < nCol; ++col) {
                // Skip if already visited, or not a land
                if(grid[row][col] == '0')       continue;
                if(visited[row][col])           continue;
                
                // New island, increment
                ++noOfIslands;
                
                dfs(grid, visited, row, col);
            }
        }
        
        return noOfIslands;
    }
};