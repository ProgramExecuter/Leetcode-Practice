class Solution {
public:
    int MOD = 1e9+7;
    int numTilings(int n) {
        if(n == 1)      return 1;
        
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        
        // Ways to fill 1 or 2 column, with or without gaps, comes out to be below
        dp[0] = {1,1};
        dp[1] = {2,2};
        
        for(int idx = 2; idx < n; ++idx) {
            ///////////
            // WHEN THERE'S A PREVOUS GAP
            ///////////
            
            // When we use   __   or     |
            //                 |       __|
            // to fill the, we only choose one of them, depending on previous choice
            int trominoRightFacing = dp[idx-1][false];
            
            // When we insert single domino to  |    or  __
            //                                  |__     |
            // we get additional gap
            int singleDominoGapFilling = dp[idx-1][true];
            
            dp[idx][true] = (1ll*trominoRightFacing + singleDominoGapFilling) % MOD;
            
            
            ///////////
            //  WHEN THERE'S NO PREVIOUS GAP
            ///////////
            // => when we put single vertical domino, we leave no gap
            int singleVertDomino = dp[idx-1][false];
            
            // => when we put 2 horizontal domino, without leaving gap
            int doubleVertDomino = dp[idx-2][false];
            
            // When we put a tromino, leaving a gap |     or    __
            //                                      |__        |
            // since there are 2 ways then, mutiply by 2
            int trominoLeftFacing = 2ll * dp[idx-2][true];
            
            dp[idx][false] = (1ll*singleVertDomino + doubleVertDomino + trominoLeftFacing) % MOD;
        }
        
        // I want to return the ways of tiling to (n-1)-th index
        // withouy leaving any gaps
        return dp[n-1][false];
    }
};