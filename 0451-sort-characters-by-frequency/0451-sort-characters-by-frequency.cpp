class Solution {
public:
    string frequencySort(string s)
    {
        map<char, int> charCnt;
        
        for(char ch : s)
            ++charCnt[ch];
        
        map<int, vector<char>, greater<int>> mp;
        
        for(auto curr : charCnt)
            mp[curr.second].push_back(curr.first);
        
        string res;
        for(auto curr : mp)
        {
            for(char ch : curr.second)
            {
                for(int i = 0; i < curr.first; ++i)
                    res += ch;
            }
        }
        
        return res;
    }
};