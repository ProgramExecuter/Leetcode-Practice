class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)      return n;                       // Base case for stairCnt = 1 or 2
        
        int prev2 = 1, prev = 2;
        
        for(int i = 3; i <= n; ++i) {                   // Calculate the ways
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};