class Solution {
public:
    int firstUniqChar(string s)
    {
        int len = s.size();
        vector<int> cntChar(26, 0), lastIdx(26, -1);
        
        for(int i = 0; i < len; ++i)
        {
            char chIdx = s[i] - 'a';
            lastIdx[chIdx] = i;
            ++cntChar[chIdx];
        }
        
        int minIdx = len;
        for(int i = 0; i < 26; ++i)
        {
            if(cntChar[i] == 1)     minIdx = min(minIdx, lastIdx[i]);
        }
        
        if(minIdx < len)
            return minIdx;
        return -1;
    }
};