class Solution {
public:
    int nthUglyNumber(int n)
    {
        if(n <= 0)  return n;
        if(n == 1)  return 1;
        
        vector<int> uglyNums(n, 0);
        uglyNums[0] = 1;
        
        int idx2 = 0, idx3 = 0, idx5 = 0;
        
        for(int i = 1; i < n; ++i)
        {
            // Next ugly number can be any one of only these
            uglyNums[i] = min(uglyNums[idx2] * 2, min(uglyNums[idx3] * 3, uglyNums[idx5] * 5));
            
            if(uglyNums[i] == uglyNums[idx2] * 2)
                ++idx2;
            if(uglyNums[i] == uglyNums[idx3] * 3)
                ++idx3;
            if(uglyNums[i] == uglyNums[idx5] * 5)
                ++idx5;
        }
        
        return uglyNums[n-1];
    }
};