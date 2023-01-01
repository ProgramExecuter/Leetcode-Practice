class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string, char> mpStrPat;
        map<char, string> mpPatStr;
        
        int idx = 0, i = 0;
        for(; i < pattern.size() and  idx < s.size(); ++i) {
            // Get current string from 's'
            string curr = "";
            while(idx < s.size()  and  s[idx] != ' ')
                curr += s[idx++];
            ++idx;
            
            // String already associated with some pattern character
            if(mpStrPat.find(curr) != mpStrPat.end()) {
                // Return FALSE, if this pattern is not same as associated pattern
                if(mpStrPat[curr] != pattern[i])
                    return false;
            }
            // String not associated with any pattern character
            else {
                // Not found any associated for string or paatern character,
                // bind these together
                if(mpPatStr.find(pattern[i]) == mpPatStr.end()) {
                    mpStrPat[curr] = pattern[i];
                    mpPatStr[pattern[i]] = curr;
                }
                // Found a string bound with pattern character
                else {
                    // Return FALSE, if this string's not same as bound string
                    if(mpPatStr[pattern[i]].compare(curr) != 0)
                        return false;
                }
            }
        }
        
        // Return FALSE, if both pattern and 's' don't have same size
        if(idx < s.size()  or  i < pattern.size())
            return false;
        
        return true;
    }
};