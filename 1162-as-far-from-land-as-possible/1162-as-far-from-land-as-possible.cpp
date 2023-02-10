class Solution {
public:
    int maxDistance(vector<vector<int>>& g, int steps = 0) {
        queue<pair<int, int>> q, q1;
        int n = g.size(), m = g[0].size();
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if (g[i][j] == 1) {
                    q.push({ i - 1, j });       q.push({ i + 1, j });
                    q.push({ i, j - 1 });       q.push({ i, j + 1 });
                }
            }
        }
      
        while (!q.empty()) {
            ++steps;
            while (!q.empty()) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                
                if(i >= 0 and j >= 0 and i < n and j < m and g[i][j] == 0) {
                    g[i][j] = steps;
                    
                    q1.push({ i - 1, j });      q1.push({ i + 1, j });
                    q1.push({ i, j - 1 });      q1.push({ i, j + 1 });
                }
            }
            swap(q1, q);
        }
        
        return steps == 1 ? -1 : steps - 1;
    }
};