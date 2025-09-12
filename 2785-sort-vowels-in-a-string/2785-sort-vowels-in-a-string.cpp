class Solution {
public:
    char isVowel(char& ch) {
        return (
            ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
        );
    }
    string sortVowels(string s) {
        unordered_map<char, int> count;
        for(char ch : s) {
            if(isVowel(ch))     count[ch] += 1;
        }

        string sortedVowels = "AEIOUaeiou";
        int idx = 0, len = s.size();
        for(int i = 0; i < len; ++i) {
            if(isVowel(s[i])) {
                while(count[sortedVowels[idx]] == 0) { ++idx; }
                s[i] = sortedVowels[idx];
                --count[sortedVowels[idx]];
            }
        }

        return s;
    }
};