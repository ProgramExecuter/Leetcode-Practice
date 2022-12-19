class Solution {
public:
    // For creating a Adjacency Vector
    void createAdjacencyVector(int n, vector<vector<int>>& edges, vector<vector<int>> &adjVect) {
        for(auto edge : edges) {
            adjVect[edge[0]].push_back(edge[1]);
            adjVect[edge[1]].push_back(edge[0]);
        }
    }
    bool bfs(int curr, int &dest, vector<vector<int>> &adjVect, vector<bool> &vis) {
        // Mark as visited
        vis[curr] = true;
        
        // Found destination, return TRUE
        if(curr == dest)
            return true;
        
        // Do BFS for each neighbor
        for(auto neighbor : adjVect[curr]) {
            // Ignore if visited
            if(vis[neighbor])   continue;
            
            // If we reached the destination, return TRUE, no need to other BFS
            if(bfs(neighbor, dest, adjVect, vis))
                return true;
        }
        
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjVect(n, vector<int>());
        
        createAdjacencyVector(n, edges, adjVect);
        
        vector<bool> vis(n, false);
        bool hasPath = bfs(source, destination, adjVect, vis);
        
        return hasPath;
    }
};