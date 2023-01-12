class Solution {
public:
    void createAdj(vector<vector<int>> &edges, vector<vector<int>> &adj)
    {
        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
    }
    vector<int> f(int curr, string &labels, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &res)
    {
        vis[curr] = true;
        vector<int> charCnt(26, 0);
        ++charCnt[labels[curr]-'a'];
        
        for(int neigh : adj[curr])
        {
            if(vis[neigh])      continue;
            vector<int> tmp = f(neigh, labels, adj, vis, res);
            
            for(int i = 0; i < 26; ++i)
                charCnt[i] += tmp[i];
        }
        
        res[curr] = charCnt[labels[curr]-'a'];
        
        return charCnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels)
    {
        vector<int> res(n, 0);
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n, vector<int>());
        
        createAdj(edges, adj);
        
        f(0, labels, adj, vis, res);
        
        return res;
    }
};