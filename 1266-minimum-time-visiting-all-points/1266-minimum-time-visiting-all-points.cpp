class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points)
    {
        int currX = points[0][0], currY = points[0][1];
        int time = 0;
        
        for(int i = 1; i < points.size(); ++i)
        {
            // Point to reach next
            int x = points[i][0], y = points[i][1];
            
            int dX = abs(currX - x), dY = abs(currY - y);
            int minD = min(dX, dY), maxD = max(dX, dY);
            
            // We move diagonally if we can
            time += minD;
            
            // For the rest we move horizontally/vertically
            time += (maxD - minD);
            
            currX = x, currY = y;
        }
        
        return time;
    }
};