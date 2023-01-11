class Solution
{
public:
    void createAdj(vector<vector<int>> &edges, vector<vector<int>> &adj)
    {
        for(auto i : edges)
        {
            adj[i[1]].push_back(i[0]);
            adj[i[0]].push_back(i[1]);
        }
    }
    int f(int curr, vector<vector<int>> &adj, vector<bool> &hasApple, vector<bool> &vis)
    {
        vis[curr] = true;
        
        int totalTime = 0;
        
        for(int neigh : adj[curr])
        {
            if(vis[neigh])  continue;
            totalTime += f(neigh, adj, hasApple, vis);
        }
        
        if(totalTime > 0  or  hasApple[curr])
            totalTime += 2;
        
        return totalTime;
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> vis(n, false);
        createAdj(edges, adj);
        
        int res = f(0, adj, hasApple, vis);
        
        if(res > 0)     res -= 2;
        
        return res;
    }
};