class Solution {
public:
    int tribonacci(int n) {
        int prev3 = 0, prev2 = 1, prev1 = 1;
        if(n == 0)          return prev3;
        else if(n == 1)     return prev2;
        else if(n == 2)     return prev1;
        
        n -= 2;
        while(n--) {
            int curr = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};