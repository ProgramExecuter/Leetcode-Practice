class Solution {
public:
    bool splitPossible(vector<int>& nums, int maxSum, int k)
    {
        int currSum = 0, splits = 1;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > maxSum)    return false;
            if(currSum + nums[i]  >  maxSum)
            {
                currSum = 0;
                ++splits;
            }
            
            currSum += nums[i];
        }
        
        return splits <= k;
    }
    int splitArray(vector<int>& nums, int k) 
    {
        int sum = 0;
        for(int x : nums)   sum += x;
        
        int left = 0, right = sum;
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(splitPossible(nums, mid, k))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};