class Solution {
public:
    int m, n;
    
    bool dfs(vector<vector<char>>& grid, int i, int j, pair<int,int> prevIdx, set<pair<int, int>>& vis, char prevChar) {
        vector<pair<int,int>> dirs({{0,1}, {1,0}, {0,-1}, {-1,0}});
        vis.insert({i,j});

        for(auto dir : dirs) {
            int newI = i + dir.first, newJ = j + dir.second;

            if(newI < 0  ||  newI >= m  ||  newJ < 0  ||  newJ >= n)
                continue;
            if((prevIdx.first == newI && prevIdx.second == newJ) || grid[newI][newJ] != prevChar)
                continue;
            if(vis.find({newI,newJ}) != vis.end()  ||  !dfs(grid,newI,newJ,{i,j},vis,grid[i][j]))
                return false;
        }

        return true;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();    n = grid[0].size();
        set<pair<int,int>> vis;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(vis.find({i,j}) != vis.end())
                    continue;

                if(!dfs(grid, i, j, {-1,-1}, vis, grid[i][j]))
                    return true;
            }
        }
        
        return false;
    }
};