class Solution
{
public:
    map<int, int> dp;
    int minDays(int n) 
    {
        if(n <= 1)  return n;
        if(dp.find(n) != dp.end())
            return dp[n];
        
        // Eat n%2 1by1 and n/2 oranges at once
        int mn1 = (n % 2) + minDays(n/2);
        
        // Eat n%3 1by1 and 2(n/3) oranges at once
        int mn2 = (n % 3) + minDays(n/3);
        
        return dp[n] = 1 + min(mn1, mn2);
    }
};