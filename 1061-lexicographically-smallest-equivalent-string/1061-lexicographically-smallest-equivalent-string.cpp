class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        int n = s1.size();
        vector<int> par(26, -1);
        
        for(int i = 0; i < n; ++i)
        {
            char ch1 = s1[i], ch2 = s2[i];
            int low, high;
            
            // If both characters are same, skip it
            if(ch1 == ch2)      continue;
            
            // If both the characters don't have any parent
            if(par[ch1-'a'] == -1  and  par[ch2-'a'] == -1)
            {
                low  = ch1-'a';
                high = ch2-'a';
            }
            // If both characters have parent
            else if(par[ch1-'a'] != -1  and  par[ch2-'a'] != -1)
            {
                low  = par[ch1-'a'];
                high = par[ch2-'a'];
            }
            // If one of them has parent and other doesn't
            else
            {
                if(par[ch1-'a'] == -1) {
                    low  = ch1-'a';
                    high = par[ch2-'a'];
                } else {
                    low  = ch2-'a';
                    high = par[ch1-'a'];
                }
            }
            
            // Make the smaller character parent of larger character, and also make it
            // parent of all character having larger character as parent
            if(low > high)      swap(high, low);
                
            par[high] = low;
            for(int i = 0; i < 26; ++i)
                if(par[i] == high)  par[i] = low;
        }
        
        // Create the result from smallest parent of each character
        string res = "";
        for(char ch : baseStr)
            if(par[ch-'a'] == -1)   res += ch;
            else                    res += char('a'+par[ch-'a']);
        
        return res;
    }
};