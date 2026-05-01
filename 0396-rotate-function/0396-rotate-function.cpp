class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), currSum = 0, res = 0, numSum = 0;
        
        for(int i = 0; i < n; ++i) {
            numSum += nums[i];
            currSum += i * nums[i];
        }
        res = currSum;

        for(int i = n-1; i > 0; --i) {
            currSum += numSum - n * nums[i];
            res = max(res, currSum);
        }

        return res;
    }
};