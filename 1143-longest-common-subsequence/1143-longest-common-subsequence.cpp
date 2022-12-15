class Solution {
public:
    int f(int idx1, int idx2, string &text1, string &text2, vector<vector<int>> &dp) {
        if(idx1 >= text1.size()  or  idx2 >= text2.size())
            return 0;
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        // Both Chars Matches
        if(text1[idx1] == text2[idx2]) {
            // Increment the length of matches subsequence by 1
            return dp[idx1][idx2] = 1 + f(idx1+1, idx2+1, text1, text2, dp);
        }
        
        // Both Don't Match
        else {
            // We can either move first or second index ahead,
            // and take max of their results
            int ch1 = f(idx1, idx2+1, text1, text2, dp);
            int ch2 = f(idx1+1, idx2, text1, text2, dp);
            
            return dp[idx1][idx2] = max(ch1, ch2);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        
        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        
        return f(0, 0, text1, text2, dp);
    }
};