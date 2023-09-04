class Solution {
public:
    int f(long long n) {
        if(n == 1)      return 0;
        
        if(n%2 == 0)
            return 1 + f(n/2);
        else {
            long long ch1 = INT_MAX, ch2 = INT_MAX;
            
            ch1 = 1 + f(n-1);
            ch2 = 1 + f(n+1);
            
            return min(ch1, ch2);
        }
    }
    int integerReplacement(int n) {
        return f(1ll*n);
    }
};