class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector<int> disFrom1(n, INT_MAX), disFrom2(n, INT_MAX);
        vector<int> vis(n, false);
        
        // For node1
        int currDist = 0, tmpN1 = node1, tmpN2 = node2;
        while(tmpN1 != -1  and  !vis[tmpN1]) {
            vis[tmpN1] = true;
            disFrom1[tmpN1] = currDist;
            tmpN1 = edges[tmpN1];
            ++currDist;
        }
        
        vis.assign(n, false);
        
        // For node2
        currDist = 0;
        while(tmpN2 != -1  and  !vis[tmpN2]) {
            vis[tmpN2] = true;
            disFrom2[tmpN2] = currDist;
            tmpN2 = edges[tmpN2];
            ++currDist;
        }
        
        int minDist = INT_MAX, resIdx = -1;
        for(int i = 0; i < n; ++i) {
            // cout << i << " =>  " << disFrom1[i] << "  " << disFrom2[i] << endl;
            int currDist = max(disFrom1[i], disFrom2[i]);
            // cout << currDist << "->" << minDist << "," << resIdx;
            if(currDist < minDist) {
                resIdx = i;
                minDist = currDist;
            }
            // cout << " -> " << minDist << "," << resIdx << endl;
        }
        
        return resIdx;
    }
};