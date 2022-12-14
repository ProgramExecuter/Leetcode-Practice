class Solution {
public:
    int rob(vector<int>& nums) {
        int noOfHouses = nums.size();
        vector<int> dp(noOfHouses, 0);
        
        for(int i = 0; i < noOfHouses; ++i) {
            int prevHouseOne = i < 1 ? 0 : dp[i-1];
            int prevHouseTwo = i < 2 ? 0 : dp[i-2];
            
            // Since this house is not adjacent
            prevHouseTwo += nums[i];
            
            dp[i] = max(prevHouseOne, prevHouseTwo);
        }
        
        // Last index contains the result
        return dp[noOfHouses-1];
    }
};