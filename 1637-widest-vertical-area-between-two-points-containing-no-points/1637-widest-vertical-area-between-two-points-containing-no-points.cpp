class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points)
    {
        vector<int> tmp;
        for(auto i : points)
            tmp.push_back(i[0]);
        sort(tmp.begin(), tmp.end());
        
        int mxWidth = 0, len = points.size();
        
        for(int i = 1; i < len; ++i)
            mxWidth = max(mxWidth, (tmp[i] - tmp[i-1]));
        
        return mxWidth;
    }
};