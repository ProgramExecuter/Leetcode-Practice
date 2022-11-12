class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size(), i = 0;
        
        // Calculate the dist, and store it's equivalent coordinates
        vector<pair<int, vector<int>>> dist;
        
        // Iterate through all coordinates
        for(auto point : points) {
            int x = point[0], y = point[1];
            
            // Push {dist, coordinates}
            dist.push_back({x*x+y*y, point});
        }
        
        // Sort the 'dist' array, to get closest K points
        sort(dist.begin(), dist.end());
        
        vector<vector<int>> ans;
        
        // Push closest K points to 'ans' array
        while(i < k) {
            ans.push_back(dist[i].second);
            ++i;
        }
        
        return ans;
    }
};