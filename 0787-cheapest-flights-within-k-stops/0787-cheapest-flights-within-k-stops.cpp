class Solution {
public:
    void createAdj(vector<vector<int>> &flights, vector<vector<pair<int, int>>> &adj) {
        for(auto i : flights)
            adj[i[0]].push_back({i[1], i[2]});
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        // Create adjacency vector
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        createAdj(flights, adj);
        
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        // { idx ,  {sum, k} }
        queue<pair<int, pair<int, int>>> q;
        q.push({src, {dist[src], 0}});
        
        while(!q.empty()) {
            auto curr = q.front();        q.pop();
            int node = curr.first;
            int currDist = curr.second.first;
            int currK = curr.second.second;
            
            if(currK > k)       continue;
            
            for(auto neigh : adj[node]) {
                int adjNode = neigh.first;
                int adjDist = neigh.second;
                
                if(currDist + adjDist < dist[adjNode]) {
                    dist[adjNode] = currDist + adjDist;
                    q.push({adjNode, {dist[adjNode], currK+1}});
                }
            }
        }
        
        if(dist[dest] == 1e9)
            return -1;
        return dist[dest];
    }
};