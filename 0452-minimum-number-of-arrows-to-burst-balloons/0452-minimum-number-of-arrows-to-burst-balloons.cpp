class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        // Record the previous points
        int prevSt = points[0][0], prevEn = points[0][1];
        int res = 1;
        
        for(auto point : points) {
            // If the current point doesn't overlap with first point of ongoing group,
            // then '++res', since we would need another arrow for new group
            if(point[0] > prevEn) {
                ++res;
                prevSt = point[0];
                prevEn = point[1];
            }
            
            // Get the smallest range we can shoot arrow
            prevSt = max(prevSt, point[0]);
            prevEn = min(prevEn, point[1]);
        }
        
        // We don't need to account for last group since at the start we have already
        // added one at the starting
        
        return res;
    }
};