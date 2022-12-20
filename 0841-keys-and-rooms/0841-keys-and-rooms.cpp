class Solution {
public:
    void dfs(int curr, vector<vector<int>>& rooms, vector<bool> &vis) {
        // Mark as visited
        vis[curr] = true;
        
        // Go check all the rooms whose keys we got
        for(int idx : rooms[curr]) {
            if(vis[idx])    continue;
            
            dfs(idx, rooms, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        
        dfs(0, rooms, vis);
        
        // If any of rooms is unvisited, return FALSE
        for(bool isVisited : vis)
            if(!isVisited)  return false;
        
        return true;
    }
};