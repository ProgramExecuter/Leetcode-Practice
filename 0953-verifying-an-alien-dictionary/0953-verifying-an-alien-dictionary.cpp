class Solution {
public:
    bool compareWords(string &s, string &t, vector<int> &charIdx) {
        int lenS = s.size(), lenT = t.size();
        
        for(int i = 0; i < lenS and i < lenT; ++i) {
            if(s[i] == t[i])    continue;
            return charIdx[s[i]-'a'] < charIdx[t[i]-'a'];
        }
        
        // This is when both strings are same thill the lesser string's size
        // S to check if 's' < 't', we check their lengths
        if(lenS > lenT)
            return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> charIdx(26, 0);
        
        // Map the char to their index
        for(int i = 0; i < order.size(); ++i)
            charIdx[order[i]-'a'] = i;
        
        // Compare each word, and check if they're in sorted fashion
        for(int i = 1; i < words.size(); ++i) {
            if(!compareWords(words[i-1], words[i], charIdx))
                return false;
        }
        
        return true;
    }
};