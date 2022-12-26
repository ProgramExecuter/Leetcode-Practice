class Solution {
public:
    bool f(int idx, vector<int> &nums, vector<int> &dp) {
        int n = nums.size();
        if(idx == n-1)          return true;
        if(idx >= n)            return false;
        
        if(dp[idx] != -1)       return dp[idx];
        
        for(int i = idx+1; i <= min(idx+nums[idx], n-1); ++i) {
            if(f(i, nums, dp))
                return dp[idx] = true;
        }
        
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        return f(0, nums, dp);
    }
};