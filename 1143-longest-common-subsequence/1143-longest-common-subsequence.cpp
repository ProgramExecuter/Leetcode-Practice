class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        vector<int> next(len2+1, 0);
        
        for(int idx1 = len1-1; idx1 >= 0; --idx1) {
            vector<int> curr(len2+1, 0);                        // Temp array for current DP
            
            for(int idx2 = len2-1; idx2 >= 0; --idx2) {
                if(text1[idx1] == text2[idx2]) {                // Both Chars Matches
                    curr[idx2] = 1 + next[idx2+1];              // Increment by subSeq's length 1
                }
                else {                                          // Chars Don't Match
                    int ch1 = curr[idx2+1];                     // We can either move first
                    int ch2 = next[idx2];                       // or second index ahead

                    curr[idx2] = max(ch1, ch2);                 // take max of the choices
                }
            }
            
            next = curr;                                        // copy 'next' to 'curr'
        }
        
        return next[0];
    }
};