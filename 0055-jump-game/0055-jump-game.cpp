class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, false);
        
        // Base case, when reches n-1, we get TRUE
        dp[n-1] = true;
        
        for(int i = n-2; i >= 0; --i) {
            // Check if in next steps, we get TRUE
            for(int j = i+1; j <= min(i+nums[i], n-1); ++j) {
                if(dp[j] == true) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};