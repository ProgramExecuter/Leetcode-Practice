class Solution 
{
public:
    int countPalindromicSubsequence(string s) 
    {
        vector<int> firstIdx(26, INT_MAX), lastIdx(26, -1);
        
        for(int i = 0; i < s.size(); ++i)
        {
            if(firstIdx[s[i]-'a'] == INT_MAX)      firstIdx[s[i]-'a'] = i;
            lastIdx[s[i]-'a'] = i;
        }
        
        int res = 0;
        
        for(int i = 0; i < 26; ++i)
        {
            if(firstIdx[i] == INT_MAX  ||  firstIdx[i] == lastIdx[i])
                continue;
            
            set<char> tmpSt(s.begin()+firstIdx[i]+1, s.begin()+lastIdx[i]);
                        
            res += tmpSt.size();
        }
        
        return res;
    }
};