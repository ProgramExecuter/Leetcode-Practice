class Solution
{
public:
    int beautySum(string s)
    {
        int len = s.size();
        int res = 0;
        
        for(int l = 0; l < len; ++l)
        {
            for(int i = 0; i < len-l; ++i)
            {
                vector<int> charCnt(26, 0);
                for(int idx = i; idx <= i+l; ++idx)
                    ++charCnt[s[idx]-'a'];
                
                int minCnt = INT_MAX, maxCnt = INT_MIN;
                for(int tmp : charCnt)
                {
                    if(tmp == 0)    continue;
                    minCnt = min(minCnt, tmp);
                    maxCnt = max(maxCnt, tmp);
                }
                
                res += maxCnt - minCnt;
            }
        }
        
        return res;
    }
};