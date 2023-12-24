class Solution {
public:
    int minOperations(string s)
    {
        int zeroOne = 0, oneZero = 0;
        
        // In 01 sequence       0 - even index,  1 - odd index
        // In 10 sequence       1 - even index,  0 - odd index
        for(int idx = 0; idx < s.size(); ++idx)
        {
            char ch = s[idx];
            
            // 01 sequence
            if(ch == '0'  and  idx % 2 == 1)
                ++zeroOne;
            if(ch == '1'  and  idx % 2 == 0)
                ++zeroOne;
            
            
            // 10 sequence
            if(ch == '0'  and  idx % 2 == 0)
                ++oneZero;
            if(ch == '1'  and  idx % 2 == 1)
                ++oneZero;
        }
        
        return min(zeroOne, oneZero);
    }
};