class Solution {
public:
    int MOD = 1e9+7;
    long long f(int idx, bool prevGap, int &n, vector<vector<int>> &dp) {
        if(idx > n)     return 0;
        if(idx == n)    return !prevGap;
        
        if(dp[idx][prevGap] != -1)
            return dp[idx][prevGap];
        
        if(prevGap) {
            return dp[idx][prevGap] = (
                f(idx+1, false, n, dp) +
                f(idx+1, true, n, dp)
            ) % MOD;
        }
        else {
            return dp[idx][prevGap] = (
                f(idx+1, false, n, dp) +
                f(idx+2, false, n, dp) +
                2ll*f(idx+2, true, n, dp)
            ) % MOD;
        }
    }
    int numTilings(int n) {
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return f(0, false, n, dp);
    }
};