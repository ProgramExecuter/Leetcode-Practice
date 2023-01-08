class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        
        // Check the slope of all pairs of 2-points
        for(int i = 0; i < n; ++i) {
            // Used for tracking the count of slopes, and also used to make sure
            // there is at least single point common in all lines, point[i]
            map<long double, int> mp;
            
            // Counts the occurence of points[i]
            int samePoint = 1;
            
            for(int j = i+1; j < n; ++j) {
                // points[i] encountered
                if(points[i][0] == points[j][0]  and  points[i][1] == points[j][1])
                    ++samePoint;
                // Infinite slope encounted, since denominator becomes 0
                else if(points[i][0] == points[j][0])
                    ++mp[INT_MAX];
                // Find the slope, and increment its count
                else {
                    long double dY = (long double)(points[j][1] - points[i][1]);
                    long double dX = (long double)(points[j][0] - points[i][0]);
                    long double slope = dY / dX;
                    ++mp[slope];
                }
            }
            
            // Add the 'samePoint' to the result, since it is also a point
            // and we add it directly, no need to check slope
            int localMax = samePoint, mxPoints = 0;
            
            // Find the maximum points for any slope, and add that group's count
            for(auto i : mp)        mxPoints = max(mxPoints, i.second);
            localMax += mxPoints;
            
            res = max(res, localMax);
        }
        
        return res;
    }
};