class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) 
    {
        int numEmptyBottles = 0, numFullBottles = numBottles;
        int totalBottlesDrank = 0;
        
        while(numFullBottles > 0)
        {
            totalBottlesDrank += numFullBottles;                // Drink Full Bottles
            numEmptyBottles += numFullBottles;                  // Full Bottles become empty bottles
            numFullBottles = numEmptyBottles / numExchange;     // Exchange empty bottles for full
            numEmptyBottles = numEmptyBottles % numExchange;    // Remaining empty bottles
        }
        
        return totalBottlesDrank;
    }
};