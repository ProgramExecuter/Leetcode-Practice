class Solution
{
public:
    int f(string &s, int idx, vector<int> &dp)
    {
        if(idx == s.size())     return 1;       // For 2 Places Selected
        if(s[idx] == '0')       return 0;       // Cannot start with start '0'
        if(idx == s.size()-1)   return 1;       // For 1 Place Selected
        
        if(dp[idx] != -1)
            return dp[idx];
        
        // Take only one place
        int ch1 = f(s, idx+1, dp), ch2 = 0;
        
        // Take two places
        int num = stoi(s.substr(idx, 2));
        
        if(num >= 1  &&  num <= 26)
            ch2 = f(s, idx+2, dp);
        
        return dp[idx] = ch1 + ch2;
    }
    int numDecodings(string s)
    {
        int len = s.size();
        vector<int> dp(len+1, -1);
        
        return f(s, 0, dp);
    }
};
