class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int nRow = grid.size(), nCol = grid[0].size(), cnt = 0;
        vector<vector<bool>> vis(nRow, vector<bool>(nCol, false));
        queue<pair<int, int>> travQ;

        for(int i = 0; i < nRow; ++i) {
            for(int j = 0; j < nCol; ++j) {
                // Border Elements with '1', these become starting point for traversal
                if(i == 0 || i == nRow-1 || j == 0 || j == nCol-1) {
                    if(grid[i][j] == 0)      continue;
                    travQ.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        int rowDir[] = {-1, 0, +1, 0};
        int colDir[] = {0, -1, 0, +1};

        while(!travQ.empty()) {
            int row = travQ.front().first;
            int col = travQ.front().second;
            travQ.pop();
            
            for(int i = 0; i < 4; ++i) {
                int nxtRow = row + rowDir[i];
                int nxtCol = col + colDir[i];

                if(nxtRow < 0 || nxtRow >= nRow || nxtCol < 0 || nxtCol >= nCol)
                    continue;
                if(vis[nxtRow][nxtCol] || grid[nxtRow][nxtCol] == 0)
                    continue;
                
                vis[nxtRow][nxtCol] = true;
                travQ.push({nxtRow, nxtCol});
            }
        }

        // We have traversed from border, all remaining 1's that are
        // not visited, cannot be visited starting from border.
        for(int i = 0; i < nRow; ++i) {
            for(int j = 0; j < nCol; ++j) {
                if(!vis[i][j]  &&  grid[i][j] == 1)
                    ++cnt;
            }
        }

        return cnt;
    }
};