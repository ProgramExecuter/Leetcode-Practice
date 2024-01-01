class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& siz) {
        sort(greed.begin(), greed.end());
        sort(siz.begin(), siz.end());
        
        int gIdx = 0, sIdx = 0, content = 0;
        
        while(gIdx < greed.size()  and  sIdx < siz.size())
        {
            if(greed[gIdx] <= siz[sIdx])
            {
                ++gIdx;
                ++sIdx;
                ++content;
            }
            else
            {
                ++sIdx;
            }
        }
        
        return content;
    }
};