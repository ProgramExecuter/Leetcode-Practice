class Solution {
public:
    // Create adjacency matrix
    void getAdjMat(vector<vector<int>>& roads, vector<vector<pair<int, int>>> &adj) {
        for(auto x : roads) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
    }
    void dfs(vector<vector<pair<int, int>>> &adj, vector<bool> &vis, int curr, int &ans) {
        // Visit all neighbour
        for(auto i : adj[curr]) {
            // Find the connected graph's minimum edge
            ans = min(ans, i.second);
            
            // Skip the visited node
            if(vis[i.first])    continue;
            
            vis[i.first] = true;        // Mark visited
            dfs(adj, vis, i.first, ans);
            // vis[i.first] = false;       // Backtrack
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>());
        
        getAdjMat(roads, adj);
        
        vector<bool> vis(n+1, false);
        
        int ans = INT_MAX;
        dfs(adj, vis, 1, ans);
        
        return ans;
    }
};