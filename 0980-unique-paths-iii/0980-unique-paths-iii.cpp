class Solution {
public:
    int f(int x, int y, int &cnt, vector<vector<int>> &grid, vector<vector<bool>> &vis, int &n, int &m) {
        if(x>=n or y>=m or x<0 or y<0 or vis[x][y] or grid[x][y]==-1)
            return 0;
        
        --cnt;      vis[x][y] = true;       // Mark as visited
        
        if(grid[x][y] == 2) {
            int tmpCnt = cnt;
            ++cnt;  vis[x][y] = false;      // Backtrack
            return tmpCnt == 0;
        }
        
        int currCnt = 0;
        
        currCnt += f(x, y+1, cnt, grid, vis, n, m);   // Right
        currCnt += f(x+1, y, cnt, grid, vis, n, m);   // Down
        currCnt += f(x-1, y, cnt, grid, vis, n, m);   // Up
        currCnt += f(x, y-1, cnt, grid, vis, n, m);   // Left
        
        vis[x][y] = false;  ++cnt;          // Backtrack
        
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
        
        int cnt = nRow*nCol - nObs;
        return f(stX, stY, cnt, grid, vis, nRow, nCol);
    }
};