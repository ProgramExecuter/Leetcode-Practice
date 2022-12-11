class Solution {
public:
    double myPow(double x, int n) {
        // if(x == double(1.0))
        //     return x;
        double ans = 1.0;
        long long tmpN = n;
        
        // Make temporary N positive
        if(tmpN < 0) {
            tmpN *= -1;
        }
        
        while(tmpN) {
            // If N is odd
            if(tmpN%2) {
                ans *= x;
                --tmpN;
            }
            // If N is even
            else {
                x *= x;
                tmpN /= 2;
            }
        }
        
        if(n < 0) {
            ans = (double(1.0))/ans;
        }
        
        return ans;
    }
};