class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        // For calculating the distance from node1 & node2
        vector<int> disFrom1(n, INT_MAX), disFrom2(n, INT_MAX);
        
        // For making sure we don't end up in a loop
        vector<int> vis(n, false);
        
        // Calculate distance from 'node1'
        int currDist = 0;
        while(node1 != -1  and  !vis[node1]) {
            vis[node1] = true;
            disFrom1[node1] = currDist;
            node1 = edges[node1];
            ++currDist;
        }
        
        vis.assign(n, false);
        
        // Calculate distance from 'node2'
        currDist = 0;
        while(node2 != -1  and  !vis[node2]) {
            vis[node2] = true;
            disFrom2[node2] = currDist;
            node2 = edges[node2];
            ++currDist;
        }
        
        // Find the result
        int minDist = INT_MAX, resIdx = -1;
        for(int i = 0; i < n; ++i) {
            int currDist = max(disFrom1[i], disFrom2[i]);
            
            if(currDist < minDist) {
                resIdx = i;
                minDist = currDist;
            }
        }
        
        return resIdx;
    }
};