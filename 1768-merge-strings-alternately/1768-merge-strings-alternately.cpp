class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        int idx1 = 0, idx2 = 0;
        string res;
        
        // Add alternating strings
        while(idx1 < len1  and  idx2 < len2)
        {
            res += word1[idx1++];
            res += word2[idx2++];
        }
        
        // Append remaining string at end
        while(idx1 < len1)
            res += word1[idx1++];
        
        while(idx2 < len2)
            res += word2[idx2++];
        
        return res;
    }
};