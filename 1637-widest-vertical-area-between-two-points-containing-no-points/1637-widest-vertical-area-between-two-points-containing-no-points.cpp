class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points)
    {
        multiset<int> tmp;
        for(auto i : points)
            tmp.insert(i[0]);
        
        int mxWidth = 0, len = points.size();
        
        int prev = -1;
        for(int i : tmp)
        {
            if(prev != -1)  mxWidth = max(mxWidth, (i-prev));
            prev = i;
        }
        
        return mxWidth;
    }
};