class Solution {
public:
    int buyChoco(vector<int>& prices, int money)
    {
        int firstLow = min(prices[0], prices[1]);
        int secondLow = max(prices[0], prices[1]);
        
        for(int i = 2; i < prices.size(); ++i)
        {
            if(prices[i] <= firstLow)
            {
                swap(firstLow, secondLow);
                firstLow = prices[i];
            }
            else if(prices[i] <= secondLow)
                secondLow = prices[i];
        }
        
        if(firstLow + secondLow <= money)
            return money - firstLow - secondLow;
        return money;
    }
};