class Solution {
public:
    // Create Adjacency Vector
    void createAdj(vector<vector<int>> &dislikes, vector<vector<int>> &adj) {
        for(auto people : dislikes) {
            adj[people[0]].push_back(people[1]);
            adj[people[1]].push_back(people[0]);
        }
    }
    bool bfs(int curr, int inGrp, vector<vector<int>> &adj, vector<int> &grp) {
        // Put the element in required group based on 'inGrp'
        // property, 1 => in 1st group    2 => in 2nd group
        grp[curr] = inGrp;
        
        // Check for all adjacent(child) node
        for(int child : adj[curr]) {
            // Not visited
            if(grp[child] == -1) {
                // If any child return FALSE, then return FALSE
                if(!bfs(child, 1-inGrp, adj, grp))
                    return false;
            }
            else {
                // Check if the child is already present in same group as parent
                // then the result is FALSE, since we cannot divide into 2 groups
                if(grp[child] == inGrp)
                    return false;
            }
        }
        
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1, vector<int>());
        createAdj(dislikes, adj);
        
        vector<int> grp(n+1, -1);       // Has detail about in which the node is
        
        for(int i = 1; i <= n; ++i) {
            // Already checked this component
            if(grp[i] != -1)    continue;
            
            if(!bfs(i, 0, adj, grp))
                return false;
        }
        
        return true;
    }
};