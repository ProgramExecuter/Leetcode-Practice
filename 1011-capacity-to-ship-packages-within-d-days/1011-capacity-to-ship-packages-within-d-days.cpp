class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // Find the total weight
        int totWeight = 0, maxEle = 0;
        for(int i : weights) {
            totWeight += i;
            maxEle = max(maxEle, i);
        }
        
        int low = maxEle, high = totWeight;
        
        while(low < high) {
            int currMaxWeight = (low + high) / 2;
            
            int parts = 1, currWeight = 0;
            for(int i = 0; i < weights.size(); ++i) {
                if(currWeight + weights[i] > currMaxWeight) {
                    currWeight = 0;
                    ++parts;
                }
                
                currWeight += weights[i];
            }
            
            if(parts > days)
                low = currMaxWeight + 1;
            else
                high = currMaxWeight;
        }
        
        return low;
    }
};