class Solution {
public:
    int countCharacters(vector<string>& words, string chars)
    {
        int cntCh[26] = {0};
        int res = 0;
        
        // Store character counts
        for(char ch : chars)
            ++cntCh[ch-'a'];
        
        for(string word : words)
        {
            bool flag = true;
            int cnt[26] = {0};
            
            for(char ch : word)
                ++cnt[ch-'a'];
            
            // Check if it is possible to make 'word'
            // from 'chars'
            for(int i = 0; i < 26; ++i)
                if(cnt[i] > cntCh[i])   flag = false;
            
            if(flag)    res += word.length();
        }
        
        return res;
    }
};