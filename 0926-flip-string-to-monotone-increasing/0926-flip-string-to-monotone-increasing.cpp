class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int idx = n-1; idx >= 0; --idx) {
            for(int prevCh = 0; prevCh <= 1; ++prevCh) {
                int flip = 1e9, noFlip = 1e9;

                if(s[idx] == '0') {
                    // Previous is '1', so we must flip and make this '1'
                    if(prevCh == 1) {
                        flip = 1 + dp[idx+1][1];
                    }
                    // Previous is '0', so we can flip or not flip it
                    else {
                        flip = 1 + dp[idx+1][1];
                        noFlip = dp[idx+1][0];
                    }
                }
                else {
                    // Since the previous char is '1', we must make this '1'
                    if(prevCh == 1) {
                        noFlip = dp[idx+1][1];
                    }
                    // Previous char is '0', so we can flip or not flip
                    else {
                        flip = 1 + dp[idx+1][0];
                        noFlip = dp[idx+1][1];
                    }
                }
                
                dp[idx][prevCh] = min(flip, noFlip);
            }
        }
        
        return dp[0][0];
    }
};