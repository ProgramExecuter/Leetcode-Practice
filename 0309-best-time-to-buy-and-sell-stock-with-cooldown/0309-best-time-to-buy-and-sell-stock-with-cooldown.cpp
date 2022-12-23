class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        // Memoization
        for(int idx = n-1; idx >= 0; --idx) {
            // We buy this stock
            int buy = -1*prices[idx] + (idx < n-1 ? dp[idx+1][1] : 0);
            
            // We don't buy this stock
            int notBuy = (idx < n-1 ? dp[idx+1][0] : 0);
        
            // We sell this stock
            int sell = prices[idx] + (idx < n-2 ? dp[idx+2][0] : 0);
            
            // We don't sell this stock
            int notSell = (idx < n-1 ? dp[idx+1][1] : 0);
            
            dp[idx][0] = max(buy, notBuy);
            dp[idx][1] = max(sell, notSell);
        }
        
        return dp[0][0];
    }
};