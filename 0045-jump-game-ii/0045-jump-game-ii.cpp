class Solution {
public:
    int jump(vector<int>& nums) {
        // Create a DP to store min. jumps needed to reach n-1 from each index
        int n = nums.size();
        
        // Base case, dp[n-1] = 0, since that is ending position, and we don't need to jump
        vector<int> dp(n, 0);
        
        // We approach this problem from back, and make our result up, such that we get
        // min. jumps needed to reach n-1 th index from 0th
        for(int idx = n-2; idx >= 0; --idx) {
            int minJump = 1e8;
        
            for(int i = 1; i <= min(n-1-idx, nums[idx]); ++i) {
                int currJump = 1;
                currJump += dp[idx + i];
                minJump = min(minJump, currJump);
            }
            
            // If minJump is >= 1e8, then it means we cannot reach n-1 from this index
            dp[idx] = minJump;
        }
        
        // Return the min. jumps needed to reach n-1 th index from 0th index
        return dp[0];
    }
};