class Solution {
public:
    int f(int idx, bool bought, vector<int> &prices, vector<vector<int>> &dp) {
        if(idx >= prices.size())
            return 0;
        
        // Already calculated
        if(dp[idx][bought] != -1)
            return dp[idx][bought];
        
        // BUY logic
        if(!bought) {
            // We buy this stock
            int buy = -1*prices[idx] + f(idx+1, true, prices, dp);
            
            // We don't buy this stock
            int notBuy = f(idx+1, false, prices, dp);
            
            return dp[idx][bought] = max(buy, notBuy);
        }
        // SELL logic
        else {
            // We sell this stock
            int sell = prices[idx] + f(idx+2, false, prices, dp);
            
            // We don't sell this stock
            int notSell = f(idx+1, true, prices, dp);
            
            return dp[idx][bought] = max(sell, notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(0, false, prices, dp);
    }
};