class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs[0].size();
        int lastIdx = n-1;
        
        // Use the first string to compare with others
        string cmp = strs[0];
        
        for(string s : strs) {
            // Initially max. matching 'idx' is -1
            int idx = -1, tmpN = s.size();
            
            for(int i = 0; i < min(n, tmpN); ++i) {
                // Current chars match, so this is idx, for now
                if(s[i] == cmp[i])  idx = i;
                // Not matching , break the loop, no need to iterate
                else                break;
            }
            
            // Take the minimum of indexes until which all string match
            lastIdx = min(lastIdx, idx);
        }
        
        // Return the string common
        return cmp.substr(0, lastIdx+1);
    }
};