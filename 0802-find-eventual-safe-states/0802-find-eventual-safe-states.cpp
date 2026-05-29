class Solution {
    vector<bool> vis, pathVis;
    vector<bool> isSafe;

public:
    bool dfsCycle(int currNode, vector<vector<int>>& adjList) {
        pathVis[currNode] = true;
        vis[currNode] = true;
        isSafe[currNode] = false;

        for(int neigh : adjList[currNode]) {
            if(!vis[neigh]) {
                // Neighbour has cycle
                if(dfsCycle(neigh, adjList)) {
                    isSafe[currNode] = false;
                    return true;
                }
            } else if(pathVis[neigh]) {
                isSafe[currNode] = false;
                return true;        // Has Cycle
            }
        }

        pathVis[currNode] = false;
        isSafe[currNode] = true;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        pathVis.assign(V, false);
        vis.assign(V, false);
        isSafe.assign(V, false);

        for(int i = 0; i < V; ++i) {
            if(vis[i])      continue;
            dfsCycle(i, graph);
        }

        vector<int> res;
        for(int i = 0; i < V; ++i) {
            if(isSafe[i])       res.push_back(i);
        }

        return res;
    }
};