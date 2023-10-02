class Solution 
{
public:
    bool winnerOfGame(string colors)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        int totAlice = 0, totBob = 0;
        int cntAlice = 0, cntBob = 0;
        
        for(char ch : colors)
        {
            if(ch == 'A')
            {
                cntBob = 0;
                ++cntAlice;
                
                if(cntAlice > 2)  { totAlice += cntAlice - 2;   cntAlice = 2; }
            }
            else
            {
                cntAlice = 0;
                ++cntBob;
                if(cntBob > 2)    { totBob += cntBob - 2;   cntBob = 2; }
            }
        }
        
        if(totAlice > totBob)   return true;
        return false;
    }
};