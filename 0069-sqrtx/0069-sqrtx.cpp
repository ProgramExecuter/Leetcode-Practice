class Solution
{
public:
    int mySqrt(int x)
    {
        long long left = 1, right = 1ll + x;
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(1ll * mid * mid  >  x)
                right = mid;
            else
                left = mid + 1;
        }
        
        return left - 1;
    }
};