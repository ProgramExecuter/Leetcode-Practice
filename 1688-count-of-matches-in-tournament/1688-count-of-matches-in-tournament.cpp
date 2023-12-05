class Solution {
public:
    int numberOfMatches(int n)
    {
        int totalMatches = 0;
        
        while(n > 1)
        {
            totalMatches += (n / 2);
            n = (n+1) / 2;
        }
        
        return totalMatches;
    }
};