class Solution {
    vector<bool> vis;
    vector<bool> pathVis;

public:
    bool dfsHasCycle(int node, vector<vector<int>>& adjList) {
        vis[node] = true;
        pathVis[node] = true;

        for(int neigh : adjList[node]) {
            if(pathVis[neigh])      return true;
            if(vis[neigh])          continue;

            if(dfsHasCycle(neigh, adjList)) {
                return true;
            }
        }

        pathVis[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>());
        vis.assign(numCourses, false);
        pathVis.assign(numCourses, false);

        for(auto curr : prerequisites)
            adjList[curr[0]].push_back(curr[1]);
        
        // If the graph has any cycle, then the courses cannot be finished
        for(int i = 0; i < numCourses; ++i) {
            if(vis[i])      continue;

            if(dfsHasCycle(i, adjList)) {
                return false;
            }
        }

        return true;
    }
};