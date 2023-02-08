class Solution {
public:
    int f(int idx, vector<int> &nums, vector<int> &dp) {
        int n = nums.size();
        if(idx == n - 1)    return 0;
        if(idx >= n)        return 1e8;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int minJump = 1e8;
        
        for(int i = 1; i <= nums[idx]; ++i) {
            int currJump = 1;
            currJump += f(idx + i, nums, dp);
            minJump = min(minJump, currJump);
        }
        
        return dp[idx] = minJump;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, -1);
        
        return f(0, nums, dp);
    }
};