class Solution {
public:
    bool check(vector<int>& nums, int divisor, int threshold)
    {
        int sum = 0;
        
        for(int num : nums)
            sum += ceil((1.0 * num) / divisor);
        
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int mxNum = INT_MIN;
        for(int n : nums)   mxNum = max(mxNum, n);
        
        int left = 1, right = mxNum;
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(check(nums, mid, threshold))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};