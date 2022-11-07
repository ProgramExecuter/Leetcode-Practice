class Solution {
public:
    void calDP(vector<int>& jobDiff, vector<vector<int>> &dp) {
        int n = jobDiff.size();
        
        for(int i = 0; i < n; ++i) {
            int mx = dp[i][i] = jobDiff[i];
            for(int j = i+1; j < n; ++j) {
                mx = max(mx, jobDiff[j]);
                dp[i][j] = mx;
            }
        }
    }
    int f(vector<int> &jobDiff, int parts, int st, vector<vector<int>> &dp, vector<vector<int>> &dpMain) {
        int en = jobDiff.size() - 1;
        if(parts == 0)      return dp[st][en];
        
        if(dpMain[st][parts] != -1)
            return dpMain[st][parts];
        
        int minDiff = 1e6;
        for(int i = st; i <= en-parts; ++i) {
            int nextPart = f(jobDiff, parts-1, i+1, dp, dpMain);
            minDiff = min(minDiff, (dp[st][i] + nextPart));
        }
        
        return dpMain[st][parts] = minDiff;
    }
    int minDifficulty(vector<int>& jobDiff, int d) {
        int n = jobDiff.size();
        
        // No of jobs < no of days, not possible
        if(n < d)       return -1;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> dpMain(n, vector<int>(d, -1));
        calDP(jobDiff, dp);
        
        int res = f(jobDiff, d-1, 0, dp, dpMain);
        
        return res;
    }
};