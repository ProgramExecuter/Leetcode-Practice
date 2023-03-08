class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Minimum and max. K
        int low = 1, high = 1e9;
        
        // Use binary-search to find K
        while(low < high) {
            int mid = low + (high - low) / 2;
            int needHours = 0;
            
            for(int curr : piles) {
                needHours += curr / mid;
                
                if(curr % mid  !=  0)
                    needHours += 1;
            }
            
            // If the needed hours to eat all piles <= H, then we check
            // if we can find a lower K
            if(needHours <= h)
                high = mid;
            // We need bigger K
            else
                low = mid + 1;
        }
        
        return low;
    }
};