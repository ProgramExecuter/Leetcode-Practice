class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        
        for(int idx1 = len1-1; idx1 >= 0; --idx1) {
            for(int idx2 = len2-1; idx2 >= 0; --idx2) {
                // Both Chars Matches
                if(text1[idx1] == text2[idx2]) {
                    // Increment the length of matches subsequence by 1
                    dp[idx1][idx2] = 1 + dp[idx1+1][idx2+1];
                }
                // Chars Don't Match
                else {
                    // We can either move first or second index ahead,
                    // and take max of their results
                    int ch1 = dp[idx1][idx2+1];
                    int ch2 = dp[idx1+1][idx2];

                    dp[idx1][idx2] = max(ch1, ch2);
                }
            }
        }
        
        return dp[0][0];
    }
};












