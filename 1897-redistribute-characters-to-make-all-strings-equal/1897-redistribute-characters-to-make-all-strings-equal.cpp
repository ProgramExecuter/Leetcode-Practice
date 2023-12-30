class Solution {
public:
    bool makeEqual(vector<string>& words) 
    {
        // To make this possible, sum count of each character from all words array
        // , and then each characters's total count should be divisble by N
        // so we can divide the string among each of indexes.
        // N => total no. of words
        vector<int> cntChar(26, 0);
        int len = words.size();
        
        for(string word : words)
        {
            for(char ch : word)
                ++cntChar[ch-'a'];
        }
        
        for(int i = 0; i < 26; ++i)
        {
            if(cntChar[i] % len  !=  0)
                return false;
        }
        
        return true;
    }
};