class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> hasChar(26*2, false);

        for(char ch : word) {
            if(ch >= 'a' && ch <= 'z') {
                hasChar[ch-'a'] = true;
            } else {
                hasChar[ch-'A' + 26] = true;
            }
        }

        int cnt = 0;
        for(int i = 0; i < 26; ++i) {
            if(hasChar[i] && hasChar[26+i])
                ++cnt;
        }

        return cnt;
    }
};