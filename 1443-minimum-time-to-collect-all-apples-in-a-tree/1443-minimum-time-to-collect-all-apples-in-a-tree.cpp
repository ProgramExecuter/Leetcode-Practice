class Solution
{
public:
    // Create the adjacency vector from edges vector
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
        // Mark this as visited
        vis[curr] = true;
        
        int totalTime = 0;
        
        // Visit all the unvisited neighbours, and add their time
        for(int neigh : adj[curr])
        {
            if(vis[neigh])  continue;
            totalTime += f(neigh, adj, hasApple, vis);
        }
        
        // If the totalTime > 0, that means we found an apple in its branches
        // OR if this node has an apple, then we found an apple in this node
        // since we found apple, then we have to come to this branch and leave as well
        // that accounts for 2 seconds, so we add that to totalTime, else we don't have
        // visit this branch/node, so no need to add it to time
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
        
        // We reduce 2 from result, if any apple is found(res > 0), beacause we have
        // added 2 seconds extra while returning the result from starting vertex, which
        // we don't have to, since we are already on that node
        if(res > 0)     res -= 2;
        
        return res;
    }
};