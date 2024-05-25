class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int mxSum = INT_MIN, currSum = 0;
        
        for(int x : nums)
        {   
            currSum += x;
            
            mxSum = max(mxSum, currSum);
            
            if(currSum < 0)
                currSum = 0;
        }
        
        return mxSum;
    }
};