class Solution {
    // 0 - no color
    // 1 - green
    // 2 - red
    vector<int> color;
    int V;
    bool isBipar = true;

public:
    void dfs(int stIdx, int prevCol, vector<vector<int>>& adjList) {
        stack<pair<int, int>> travSt;
        travSt.push({stIdx, 1});
        color[stIdx] = 1;

        while(!travSt.empty()) {
            int currIdx = travSt.top().first;
            int currCol = travSt.top().second;
            travSt.pop();

            for(int neigh : adjList[currIdx]) {
                if(color[neigh] == 0) {
                    int newColor = currCol == 1 ? 2 : 1;
                    travSt.push({neigh, newColor});
                    color[neigh] = newColor;
                } else if(color[neigh] == currCol) {
                    isBipar = false;
                    return;
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        V = graph.size();
        color.assign(V, 0);

        for(int i = 0; i < V; ++i) {
            if(color[i] != 0)   continue;
            dfs(i, 1, graph);
        }

        return isBipar;
    }
};