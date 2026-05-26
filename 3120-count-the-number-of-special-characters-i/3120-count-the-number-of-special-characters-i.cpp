class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, bool> charUsed;
        
        int cnt = 0;
        for(char ch : word) {
            if(ch >= 'a' && ch <= 'z') {
                if(charUsed.count(ch) == 0)
                    charUsed[ch] = false;
                if(charUsed.count(toupper(ch)) > 0 && !charUsed[toupper(ch)] && !charUsed[ch]) {
                    ++cnt;
                    charUsed[ch] = true;
                    charUsed[toupper(ch)] = true;
                }
            } else {
                if(charUsed.count(ch) == 0)
                    charUsed[ch] = false;
                if(charUsed.count(tolower(ch)) > 0 && !charUsed[tolower(ch)] && !charUsed[ch]) {
                    ++cnt;
                    charUsed[ch] = true;
                    charUsed[tolower(ch)] = true;
                }
            }
        }

        return cnt;
    }
};