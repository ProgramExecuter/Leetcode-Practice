class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        // Tabulation => Bottom-Up
        for(int st = n-1; st >= 0; --st) {
            int maxSum = 0, maxEle = -1;
            // Check for each partition
            for(int i = st; i < min(st+k, n); ++i) {
                // Get max element from current partition
                maxEle = max(maxEle, arr[i]);

                // Calculate sum
                int tmp = (i-st+1)*maxEle + dp[i+1];
                
                // Get maximum sum from all partitions
                maxSum = max(maxSum, tmp);
            }
            dp[st] = maxSum;
        }

        return dp[0];
    }
};