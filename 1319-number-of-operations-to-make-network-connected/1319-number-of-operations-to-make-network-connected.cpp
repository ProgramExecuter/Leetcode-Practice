class Solution {
    void dfs(vector<int> conn[], vector<bool> &visited, int i) {
        visited[i] = true;
        for(int v : conn[i]) {
            if(!visited[v]) 
                dfs(conn, visited, v);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& num) {
        int len = num.size();
        
        if(len < n-1)       return -1;

        vector<int> conn[n];

        for(auto v : num) {
            conn[v[0]].push_back(v[1]);
            conn[v[1]].push_back(v[0]);
        }

        int ans = 0;
        vector<bool> visited(n, false);

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(conn, visited, i);
                ++ans;
            }
        }

        return ans-1;
    }
};