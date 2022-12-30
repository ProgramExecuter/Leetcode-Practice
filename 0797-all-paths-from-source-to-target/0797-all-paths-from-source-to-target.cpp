class Solution {
public:
    void f(int curr, vector<int> currPath, vector<vector<int>>& graph, vector<vector<int>>& res) {
        // Put this node on the current path
        currPath.push_back(curr);
        
        // If we got to 'n-1' th node, then put the current path in result
        if(curr == graph.size()-1)
            res.push_back(currPath);
        
        // Visit neighbours and BFS
        for(int neigh : graph[curr])
            f(neigh, currPath, graph, res);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        
        f(0, {}, graph, res);
        
        return res;
    }
};