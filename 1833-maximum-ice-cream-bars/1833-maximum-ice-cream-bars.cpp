class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int idx = 0, n = costs.size(), iceCreamBought = 0;
        
        while(idx < n  and  coins >= costs[idx]) {
            ++iceCreamBought;
            coins -= costs[idx++];
        }
        
        return iceCreamBought;
    }
};