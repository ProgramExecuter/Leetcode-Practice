class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int nRow = grid.size(), nCol = grid[0].size();
        // vector<vector<bool>> vis(nRow, vector<bool>(nCol, false));
        queue<pair<int, int>> travQ;

        // Start with already rotten oranges
        for(int i = 0; i < nRow; ++i) {
            for(int j = 0; j < nCol; ++j) {
                if(grid[i][j] == 2) {
                    travQ.push({i, j});
                    // vis[i][j] = true;
                }
            }
        }

        int minMinutes = 0;
        while(!travQ.empty()) {
            int len = travQ.size();
            bool hasGoodOranges = false;

            while(len--) {
                int currI = travQ.front().first, currJ = travQ.front().second;
                travQ.pop();

                if(grid[currI][currJ] == 1) {
                    hasGoodOranges = true;
                    grid[currI][currJ] = 2;
                }

                // Left
                if(currJ > 0  &&  grid[currI][currJ-1] == 1)
                    travQ.push({currI, currJ-1});
                // Right
                if(currJ < nCol-1  &&  grid[currI][currJ+1] == 1)
                    travQ.push({currI, currJ+1});
                // Up
                if(currI > 0  &&  grid[currI-1][currJ] == 1)
                    travQ.push({currI-1, currJ});
                // Down
                if(currI < nRow-1  &&  grid[currI+1][currJ] == 1)
                    travQ.push({currI+1, currJ});
            }

            if(hasGoodOranges)      ++minMinutes;
        }

        // Check if there are any good oranges
        for(int i = 0; i < nRow; ++i) {
            for(int j = 0; j < nCol; ++j) {
                if(grid[i][j] == 1)     return -1;
            }
        }

        return max(0, minMinutes);
    }
};