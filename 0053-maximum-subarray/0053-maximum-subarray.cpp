class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], currSum = nums[0];
        bool skippedFirst = false;

        for(int num : nums) {
            if(!skippedFirst) {
                skippedFirst = true;
                continue;
            }

            if(currSum <= 0  ||  currSum + num <= 0) {
                maxSum = max(maxSum, currSum);
                currSum = 0;
            } 

            currSum += num;
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};