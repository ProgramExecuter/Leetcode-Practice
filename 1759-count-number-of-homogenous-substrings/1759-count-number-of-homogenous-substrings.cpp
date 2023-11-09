int MOD = 1e9+7;
class Solution {
public:
    int countHomogenous(string s)
    {
        int res = 0, currCnt = 0;
        char prevCh = s[0];
        
        for(char ch : s)
        {
            if(ch == prevCh)
                ++currCnt;
            else
            {
                long long tmp = ( 1ll * currCnt * (currCnt + 1) ) / 2;
                res += (tmp % MOD);
                
                currCnt = 1;
            }
            
            prevCh = ch;
        }
        
        long long tmp = ( 1ll * currCnt * (currCnt + 1) ) / 2;
        res += (tmp % MOD);
        
        return res;
    }
};