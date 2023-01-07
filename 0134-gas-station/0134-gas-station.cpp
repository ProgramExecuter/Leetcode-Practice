class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currGas = 0, idx = 0, n = gas.size();
        
        // Check if we have required fuel
        int totFuel = 0;
        for(int i = 0; i < n; ++i)
            totFuel += (gas[i] - cost[i]);
        
        // Return -1, since we can't make journey due to insufficient fuel
        if(totFuel < 0)
            return -1;
        
        for(int i = 0; i < n; ++i) {
            // If fuel is -ve at any point, then we restart ourjourney from next station
            if(currGas < 0) {
                idx = i;
                currGas = 0;
            }
            currGas += (gas[i] - cost[i]);
        }
        
        return idx;
    }
};