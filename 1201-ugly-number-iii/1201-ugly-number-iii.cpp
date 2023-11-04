class Solution {
public:
    bool enough(int n, int num, int a, int b, int c)
    {
        long long ab = 1ll * a * b / gcd(a, b);
        long long bc = 1ll * b * c / gcd(b, c);
        long long ca = 1ll * c * a / gcd(c, a);
        long long abc = 1ll * a * bc / gcd(a, bc);
        
        long long cnt = 0ll + num/a + num/b + num/c - num/ab - num/bc - num/ca + num/abc;
        
        return cnt >= n;
    }
    int nthUglyNumber(int n, int a, int b, int c)
    {
        int left = 1, right = 2e9;
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(enough(n, mid, a, b, c))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};