class Solution {
public:
    // Check if this character is a vowel
    bool isVowel(char ch) {
        vector<char> vowels = {'a','e','i','o','u',
                               'A','E','I','O','U'};
        
        for(char vowel : vowels)
            if(ch == vowel)     return true;
        
        return false;
    }
    bool halvesAreAlike(string s) {
        int diffCnt = 0, n = s.size();
        
        // Increment cnt if in first  half we encounter a vowel
        // Decrement cnt if in second half we encounter a vowel
        for(int i = 0; i < n/2; ++i) {
            if(isVowel(s[i]))       ++diffCnt;
            if(isVowel(s[n/2+i]))   --diffCnt;
        }
        
        // If cnt is equal on both halves, it is alike
        if(diffCnt == 0)    return true;
        
        return false;
    }
};