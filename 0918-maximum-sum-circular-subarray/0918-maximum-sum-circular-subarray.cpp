class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totSum = 0, currMinSum = 0, currMaxSum = 0;
        int maxSum = INT_MIN, minSum = INT_MAX;
        
        for(int x : nums) {
            totSum += x;
            minSum = min(minSum, x);
            maxSum = max(maxSum, x);
            
            if(currMaxSum + x  <  0)
                currMaxSum = 0;
            else {
                currMaxSum += x;
                maxSum = max(maxSum, currMaxSum);
            }
            
            if(currMinSum + x > 0)
                currMinSum = 0;
            else {
                currMinSum += x;
                minSum = min(minSum, currMinSum);
            }
        }
        
        int res = max(maxSum, (totSum - minSum));
        
        if(minSum == totSum)
            return maxSum;
        return res;
        
        // https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass
    }
};