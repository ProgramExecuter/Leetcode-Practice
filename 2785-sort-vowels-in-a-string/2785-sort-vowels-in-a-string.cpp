class Solution {
public:
    char isVowel(char& ch) {
        return (
            ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'
        );
    }
    string sortVowels(string s) {
        multiset<char> vowels;
        for(char ch : s) {
            if(isVowel(ch))     vowels.insert(ch);
        }

        string res;
        auto itr = vowels.begin();
        for(char ch : s) {
            if(isVowel(ch)) {
                res += *itr;
                ++itr;
            } else {
                res += ch;
            }
        }

        return res;
    }
};