class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mnPrice = prices[0], mxProfit = 0;
        
        for(int i = 1; i < prices.size(); ++i) {
            int profit = prices[i] - mnPrice;
            mnPrice = min(mnPrice, prices[i]);
            
            mxProfit = max(mxProfit, profit);
        }
        
        return mxProfit;
    }
};