class Solution {
public:
    int passThePillow(int n, int time)
    {
        int noOfTimes = time / (n-1);
        int remaining = time % (n-1);
        
        if(noOfTimes % 2 == 0)
            return (1 + remaining);
        else
            return (n - remaining);
    }
};
