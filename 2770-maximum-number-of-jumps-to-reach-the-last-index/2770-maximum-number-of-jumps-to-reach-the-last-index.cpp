class Solution {
public:
    int solve(int i, vector<int>& nums, int target, vector<int>& dp, int& n) {
        // If we reach last index, no more jumps needed
        if(i == n - 1)
            return 0;

        // Return already computed result
        if(dp[i] != -2)
            return dp[i];

        // Try all possible next jumps
        int ans = -1;
        for(int j = i + 1; j < n; j++) {
            // Check jump condition
            if(abs(nums[j] - nums[i]) <= target) {
                int temp = solve(j, nums, target, dp, n);
                // Update maximum jumps
                if(temp != -1)  ans = max(ans, 1 + temp);
            }
        }
        // Store and return answer
        return dp[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        // -2 means not calculated yet
        vector<int> dp(n, -2);

        return solve(0, nums, target, dp, n);
    }
};