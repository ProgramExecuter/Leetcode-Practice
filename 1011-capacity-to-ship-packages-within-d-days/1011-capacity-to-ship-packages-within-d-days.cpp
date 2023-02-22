class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // Find the total weight
        int totWeight = 0, maxEle = 0;
        for(int i : weights) {
            totWeight += i;
            maxEle = max(maxEle, i);
        }
        
        // minimum max. limit should be maximum weighted box
        int low = maxEle, high = totWeight;
        
        // Check using binary search for min. maximum weight limit
        while(low < high) {
            int currMaxWeight = (low + high) / 2;
            int parts = 1, currWeight = 0;
            
            for(int i = 0; i < weights.size(); ++i) {
                // We need to make another round
                if(currWeight + weights[i] > currMaxWeight) {
                    currWeight = 0;
                    ++parts;
                }
                
                currWeight += weights[i];
            }
            
            // Need higher weight limit
            if(parts > days)
                low = currMaxWeight + 1;
            // Try to find lower weight limit, if possible
            else
                high = currMaxWeight;
        }
        
        return low;
    }
};