class Solution {
public:
    int f(int idx, char prevCh, int &n, string &s, vector<vector<int>> &dp) {
        if(idx == n)    return 0;
        
        if(dp[idx][prevCh-'0'] != -1)
            return dp[idx][prevCh-'0'];
        
        int flip = 1e9, noFlip = 1e9;
        
        if(s[idx] == '0') {
            // Previous is '1', so we must flip and make this '1'
            if(prevCh == '1') {
                flip = 1 + f(idx+1, '1', n, s, dp);
            }
            // Previous is '0', so we can flip or not flip it
            else {
                flip = 1 + f(idx+1, '1', n, s, dp);
                noFlip = f(idx+1, '0', n, s, dp);
            }
        }
        else {
            // Since the previous char is '1', we must make this '1'
            if(prevCh == '1') {
                noFlip = f(idx+1, '1', n, s, dp);
            }
            // Previous char is '0', so we can flip or not flip
            else {
                flip = 1 + f(idx+1, '0', n, s, dp);
                noFlip = f(idx+1, '1', n, s, dp);
            }
        }

        return dp[idx][prevCh-'0'] = min(flip, noFlip);
    }
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        return f(0, '0', n, s, dp);
    }
};