class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size(), cntRemoved = 0;
        
        // Used for storing highest char until previous string
        // on each index
        vector<int> curr(n, -1);
        
        for(string s : strs) {
            for(int i = 0; i < n; ++i) {
                int currChar = s[i]- 'a';
                
                // If current character is < previous max. char
                // then mark it removed by assigning 1e6, so no next chars
                // can be greater than this
                if(currChar < curr[i])
                    curr[i] = 1e6;
                // Make the current character as max until now
                // for this index.
                else
                    curr[i] = currChar;
            }
        }
        
        // Check the removed indexes
        for(auto i : curr)
            if(i == 1e6)     ++cntRemoved;
        
        return cntRemoved;
    }
};