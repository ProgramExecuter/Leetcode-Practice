class Solution {
    int n, m;
    vector<vector<bool>> vis;
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        vis[i][j] = true;

        // Left
        if(i > 0  &&  !vis[i-1][j]  &&  grid[i-1][j] == '1')
            dfs(grid, i-1, j);
        // Right
        if(i < n-1  &&  !vis[i+1][j]  &&  grid[i+1][j] == '1')
            dfs(grid, i+1, j);
        // Up
        if(j > 0  &&  !vis[i][j-1]  &&  grid[i][j-1] == '1')
            dfs(grid, i, j-1);
        // Down
        if(j < m-1  &&  !vis[i][j+1]  &&  grid[i][j+1] == '1')
            dfs(grid, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cntIsland = 0;
        vis.assign(n, vector<bool>(m, false));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == '0')       continue;
                if(vis[i][j])               continue;

                ++cntIsland;
                dfs(grid, i, j);
            }
        }

        return cntIsland;
    }
};