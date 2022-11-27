class Solution {
public:
    void util(string &digits, vector<vector<char>> &mapChar, int idx, string curr, vector<string> &ans) {
        if(idx == digits.size()) {                          // End of string, push the current string
            if(curr.size() > 0)                             // Do not add empty string to result
                ans.push_back(curr);
            return;
        }
        
        int charNum = digits[idx] - '0';                    // Get integer form of input char
        
        for(char ch : mapChar[charNum])
            util(digits, mapChar, idx+1, curr+ch, ans);     // Add this character to current string
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        vector<vector<char>> mapChar({                      // Mapping of 'number' to its possible 'chars'
            {},
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'},
        });
        
        string curr;
        util(digits, mapChar, 0, curr, ans);
        
        return ans;
    }
};