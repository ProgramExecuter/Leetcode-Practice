class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end());
        
        int mxWidth = 0, len = points.size();
        
        for(int i = 1; i < len; ++i)
            mxWidth = max(mxWidth, (points[i][0] - points[i-1][0]));
        
        return mxWidth;
    }
};