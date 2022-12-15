class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        
        vector<int> prev(n2+1, 0), curr(n2+1, 0);               // Take 'curr' and 'prev'
        
        for(int idx1 = 1; idx1 <= n1; ++idx1) {
            for(int idx2 = 1; idx2 <= n2; ++idx2) {             // Check for both strings
                if(text1[idx1-1] == text2[idx2-1])              // If curr char matches, +1
                    curr[idx2] = 1 + prev[idx2-1];
                else                                            // Else, max of 2 choices
                    curr[idx2] = max(prev[idx2], curr[idx2-1]); // whether to move idx1 or idx2
            }
            prev = curr;
        }
        
        return prev[n2];
    }
};