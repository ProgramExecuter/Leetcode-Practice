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

        string res, sortedVowels = "AEIOUaeiou";
        auto idx = 0;
        for(char ch : s) {
            if(isVowel(ch)) {
                while(count[sortedVowels[idx]] == 0) { ++idx; }
                res += sortedVowels[idx];
                --count[sortedVowels[idx]];
            } else {
                res += ch;
            }
        }

        return res;
    }
};