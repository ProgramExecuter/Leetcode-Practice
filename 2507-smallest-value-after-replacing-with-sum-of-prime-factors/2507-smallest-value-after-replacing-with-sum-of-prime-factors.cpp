class Solution {
public:
    int smallestValue(int n) {
        int prev = -1;
        
        while(1) {
            int sum = 0;
            
            // Check for prime factors, no need to check for prime,
            // because we are dividing from lowest, thus first division whose
            // remainder is 0, will always be prime number
            for(int i = 2; i <= n;) {
                // Prime Number and it divided
                if(n % i == 0) {
                    sum += i;
                    n /= i;
                }
                // Move Ahead(Maybe a prime number, but didn't divide)
                else {
                    ++i;
                }
            }
            
            // We get new 'n'
            n = sum;
            
            // if n == prev, this is final result, since we got prime 'n'
            if(n == prev)
                break;
            
            prev = n;
        }
        
        return n;
    }
};
