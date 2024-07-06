class Solution {
public:
    int passThePillow(int n, int time)
    {
        int noOfTimes = time / (n-1);
        int remaining = time % (n-1);
        
        int finalIdx = 0;
        
        if(noOfTimes % 2 == 0)
            finalIdx = 1 + remaining;
        else
            finalIdx = (n - remaining);
        
        return finalIdx;
    }
};
