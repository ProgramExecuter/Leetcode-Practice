class Solution {
public:
    long long dfs(int curr, int &seats, vector<vector<int>> &adj, vector<bool> &vis, long long &res) {
        // Mark as visited
        vis[curr] = true;
        
        // 1 for current node
        long long people = 1ll;
        
        for(int neigh : adj[curr]) {
            // Already visited
            if(vis[neigh])     continue;
            
            int tmp = dfs(neigh, seats, adj, vis, res);
            people += tmp;
            
            // Add the fuel the people from immediate children branch need to get to this node
            res += (tmp + seats-1) / seats;
        }
        
        return people;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<bool> vis(n, false);
        vis[0] = true;
        
        // Adjacency vector
        vector<vector<int>> adj(n, vector<int>());
        for(auto i : roads) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        long long resScore = 0ll;
        dfs(0, seats, adj, vis, resScore);
        
        return resScore;
    }
};