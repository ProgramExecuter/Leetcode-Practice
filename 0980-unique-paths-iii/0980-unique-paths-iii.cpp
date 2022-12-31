class Solution {
public:
    int f(int x, int y, int &cnt, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
        // Return  0 , if indexes out-of-range 
        // or already visited or the grid has obstacles
        if( x >= grid.size()  or  y >= grid[0].size()  
            or  x < 0  or  y < 0  or vis[x][y]
            or grid[x][y] == -1 
          )
            return 0;
        
        --cnt;      vis[x][y] = true;                   // Mark as visited
        
        // Found the ending node
        if(grid[x][y] == 2) {
            int tmpCnt = cnt;
            
            ++cnt;  vis[x][y] = false;                  // Backtrack
            
            return tmpCnt == 0;
        }
        
        int currCnt = 0;
        
        // Sum all the results from all directions
        currCnt += f(x, y+1, cnt, grid, vis);           // Right
        currCnt += f(x+1, y, cnt, grid, vis);           // Down
        currCnt += f(x-1, y, cnt, grid, vis);           // Up
        currCnt += f(x, y-1, cnt, grid, vis);           // Left
        
        vis[x][y] = false;  ++cnt;                      // Backtrack
        
        return currCnt;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int stX, stY, enX, enY, nObs = 0;
        int nRow = grid.size(), nCol = grid[0].size();
        vector<vector<bool>> vis(nRow, vector<bool>(nCol, false));
        
        // Find the starting and ending points
        for(int i = 0; i < nRow; ++i) {
            for(int j = 0; j < nCol; ++j) {
                if(grid[i][j] == 1) {
                    stX = i;    stY = j;
                }
                else if(grid[i][j] == -1)
                    ++nObs;
            }
        }
        
        // No of grid we need to visit
        int cnt = nRow*nCol - nObs;
        
        return f(stX, stY, cnt, grid, vis);
    }
};