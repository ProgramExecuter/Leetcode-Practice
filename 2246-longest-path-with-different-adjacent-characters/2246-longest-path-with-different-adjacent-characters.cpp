class Solution {
public:
    int f(int curr, string &s, vector<vector<int>> &adj, int &maxPathLen)
    {
        // Find the longest 2 subtree for this node
        int max1 = 0, max2 = 0;
        for(int child : adj[curr])
        {
            int tmp = f(child, s, adj, maxPathLen);
            if(s[child] == s[curr])     continue;
            
            if(tmp > max2)      max2 = tmp;
            if(max2 > max1)     swap(max1, max2);
        }
        
        // The path that only includes current node(+1), and its 2 subtrees(at max)
        int currMaxPath = 1 + max1 + max2;
        maxPathLen = max(maxPathLen, currMaxPath);
        
        // Return the path length of one subtree and include this node(so +1)
        return max1 + 1;
    }
    int longestPath(vector<int>& parent, string s)
    {
        int n = parent.size(), maxPathLen = 0;
        vector<vector<int>> adj(n, vector<int>());
        
        // Create adjacency vector
        for(int i = 1; i < parent.size(); ++i)
            adj[parent[i]].push_back(i);
        
        f(0, s, adj, maxPathLen);
        
        return maxPathLen;
    }
};