class Solution {
public:
    bool foundEnough(int num, int m, int n, int k)
    {
        int cntSmaller = 0;
        
        for(int i = 1; i <= m; ++i)
        {
            // Each column element is multiple of its row number
            int nSmall = min(num / i, n);
            
            if(nSmall == 0)     // This and next columns have all elements > 'num'
                break;          // So early exit
            
            cntSmaller += nSmall;
        }
        
        // Atleast 'k' numbers are smaller than 'num'
        return cntSmaller >= k;
    }
    int findKthNumber(int m, int n, int k)
    {
        int left = 1, right = m*n;
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(foundEnough(mid, m, n, k))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};