class Solution {
public:
//     int f(int idx, vector<int> &nums, vector<int> &dp) {
//         int n = nums.size();
//         if(idx == n - 1)    return 0;
//         if(idx >= n)        return 1e8;
        
//         if(dp[idx] != -1)
//             return dp[idx];
        
//         int minJump = 1e8;
        
//         for(int i = 1; i <= nums[idx]; ++i) {
//             int currJump = 1;
//             currJump += f(idx + i, nums, dp);
//             minJump = min(minJump, currJump);
//         }
        
//         return dp[idx] = minJump;
//     }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        
        for(int idx = n-2; idx >= 0; --idx) {
            int minJump = 1e8;
        
            for(int i = 1; i <= min(n-1-idx, nums[idx]); ++i) {
                int currJump = 1;
                currJump += dp[idx + i];
                minJump = min(minJump, currJump);
            }
            
            dp[idx] = minJump;
        }
        
        return dp[0];
    }
};