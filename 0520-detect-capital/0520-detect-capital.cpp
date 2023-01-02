class Solution {
public:
    bool detectCapitalUse(string word) {
        bool capital = false;
        int capCnt = 0, n = word.size();
        
        if(word[0] >= 'A'  and  word[0] <= 'Z')
            capital = true;
        
        // Count the capital letters after first character
        for(int i = 1; i < n; ++i) {
            if(word[i] >= 'A'  and  word[i] <= 'Z')
                ++capCnt;
        }
        
        // All characters are Caps or all characters are small 
        // or only first is Caps, then return TRUE
        if((capCnt == n-1  and  capital)  or  capCnt == 0)
            return true;
        
        return false;
    }
};