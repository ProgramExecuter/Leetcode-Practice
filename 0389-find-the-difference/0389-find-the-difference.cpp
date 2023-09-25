class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26, 0);
        
        for(char ch : s)    ++cnt[ch-'a'];
        for(char ch : t)    --cnt[ch-'a'];
        
        for(int i = 0; i < 26; ++i)
            if(cnt[i] != 0)     return char('a'+i);
        
        return 'a';
    }
};