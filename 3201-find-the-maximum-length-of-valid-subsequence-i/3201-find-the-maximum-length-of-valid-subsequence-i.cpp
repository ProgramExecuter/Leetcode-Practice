class Solution {
public:
    int maximumLength(vector<int>& nums) 
    {
        int allEven = 0, allOdd = 0, oddEven = 0, evenOdd = 0;
        bool nextOddEven = 1, nextEvenOdd = 0;
        
        for(int num : nums)
        {
            if(num % 2)     ++allOdd;
            else            ++allEven;
            
            if(num % 2 == nextOddEven)
            {
                ++oddEven;
                nextOddEven = 1 - nextOddEven;
            }
            if(num % 2 == nextEvenOdd)
            {
                ++evenOdd;
                nextEvenOdd = 1 - nextEvenOdd;
            }
        }
        
        return max(max(allEven, allOdd), max(evenOdd, oddEven));
    }
};