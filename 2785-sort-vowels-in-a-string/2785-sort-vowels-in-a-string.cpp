class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
          ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
    string sortVowels(string s) 
    {
        vector<char> vowels;
        for(char ch : s)
            if(isVowel(ch))     vowels.push_back(ch);
        
        sort(vowels.begin(), vowels.end());
        
        int i = 0;
        for(int idx = 0; idx < s.size(), i < vowels.size(); ++idx)
            if(isVowel(s[idx]))     s[idx] = vowels[i++];
        
        return s;
    }
};