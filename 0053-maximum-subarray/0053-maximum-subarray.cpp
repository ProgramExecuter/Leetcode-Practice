class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int mxSum = INT_MIN, currSum = 0, hasNum = false;
        
        for(int x : nums)
        {   
            currSum += x;
            hasNum = true;
            
            mxSum = max(mxSum, currSum);
            
            if(currSum < 0)
            {
                currSum = 0;
                hasNum = false;
            }
        }
        if(hasNum)      mxSum = max(mxSum, currSum);
        
        return mxSum;
    }
};