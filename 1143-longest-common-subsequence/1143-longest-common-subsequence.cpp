class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        
        vector<int> next(len2+1, 0);
        
        for(int idx1 = len1-1; idx1 >= 0; --idx1) {
            vector<int> curr(len2+1, 0);
            
            for(int idx2 = len2-1; idx2 >= 0; --idx2) {
                // Both Chars Matches
                if(text1[idx1] == text2[idx2]) {
                    // Increment the result length of subsequence by 1
                    curr[idx2] = 1 + next[idx2+1];
                }
                // Chars Don't Match
                else {
                    // We can either move first or second index ahead,
                    // and take max of their results
                    int ch1 = curr[idx2+1];
                    int ch2 = next[idx2];

                    curr[idx2] = max(ch1, ch2);
                }
            }
            
            next = curr;
        }
        
        return next[0];
    }
};












