class Solution {
public:
    bool canBeDone(vector<int>& bloomDay, int days, int m, int k)
    {
        int currCnt = 0, cntMade = 0;
        
        for(int curr : bloomDay)
        {
            if(curr > days)     // Didn't bloom till now
            {
                cntMade += currCnt / k;
                currCnt = 0;
            }
            else                // Bloomed, can be used in bouquet
            {
                ++currCnt;
            }
        }
        cntMade += currCnt / k;
        
        // Check is bouqets that can be made is > required bouqets to be made
        return cntMade >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k)
    {
        // Not enough flowers
        if(1ll * m * k  >  bloomDay.size())
            return -1;
        
        int mxBloom = 0;
        for(int x : bloomDay)   mxBloom = max(mxBloom, x);
        
        // Find the min. no of days required using BINARY SEARCH
        int left = 1, right = mxBloom;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(canBeDone(bloomDay, mid, m, k))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};