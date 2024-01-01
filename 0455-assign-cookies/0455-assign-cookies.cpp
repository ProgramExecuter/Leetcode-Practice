class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& siz) {
        sort(greed.begin(), greed.end());
        sort(siz.begin(), siz.end());
        
        int gIdx = 0, sIdx = 0, content = 0;
        int lenG = greed.size(), lenS = siz.size();
        
        while(gIdx < lenG  and  sIdx < lenS)
        {
            if(greed[gIdx] <= siz[sIdx])
                ++gIdx;
            ++sIdx;
        }
        
        return gIdx;
    }
};