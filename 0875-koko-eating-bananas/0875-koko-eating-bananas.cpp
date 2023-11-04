class Solution {
public:
    bool possibleToEatAll(vector<int>& piles, int speed, int h)
    {
        for(int pile : piles)
            h -= (pile + speed - 1) / speed;
        
        return h >= 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mxPile = 0;
        for(int x : piles)  mxPile = max(mxPile, x);
        
        int left = 1, right = mxPile;
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(possibleToEatAll(piles, mid, h))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};