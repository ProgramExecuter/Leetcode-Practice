class Solution {
public:
    // Create adjacency vector
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
        // Mark this node as visited
        vis[curr] = true;
        vector<int> charCnt(26, 0);
        ++charCnt[labels[curr]-'a'];        // Count the current node's label
        
        for(int neigh : adj[curr])
        {
            // Skip if already visited
            if(vis[neigh])      continue;
            
            // Check for all neighbours, and get their character counts
            // since they are sub-trees, we add their char's count
            vector<int> tmp = f(neigh, labels, adj, vis, res);
            for(int i = 0; i < 26; ++i)
                charCnt[i] += tmp[i];
        }
        
        // Assign result for this node as, no. of character of this node's label
        // found in it, and its subtrees
        res[curr] = charCnt[labels[curr]-'a'];
        
        // Return the character count for current subtree
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