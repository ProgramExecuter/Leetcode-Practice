#define MOD 1000000007
class Solution {
public:
    int dp[31][1001] = { 0 };
    int numRollsToTarget(int n, int k, int target) 
    {
        if(n == 0  ||  target <= 0)
            return n == target;
        if(dp[n][target] != 0)
            return dp[n][target] - 1;
     
        int res = 0;
        for(int i = 1; i <= k; ++i)
            res = (res + numRollsToTarget(n-1, k, target-i)) % 1000000007;
        
        dp[n][target] = res + 1;
        return res;
    }
};