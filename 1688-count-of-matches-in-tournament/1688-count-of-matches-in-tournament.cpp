class Solution {
public:
    int numberOfMatches(int n)
    {
        int totalMatches = 0;
        
        while(n > 1)
        {
            totalMatches += (n / 2);
            if(n % 2 == 1)
                n = (n / 2) + 1;
            else
                n /= 2;
        }
        
        return totalMatches;
    }
};