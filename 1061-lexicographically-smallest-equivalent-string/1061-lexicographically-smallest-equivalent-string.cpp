class Solution {
public:
    vector<int> par;
    Solution()
    {
        par = vector<int>(26, -1);
    }
    int find(int x)
    {
        if(par[x] == -1)    return x;
        return par[x] = find(par[x]);
    }
    void Union(int x, int y)
    {
        x = find(x);    y = find(y);
        if(x != y)      par[max(x, y)] = min(x, y); 
    }
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        for(auto i = 0; i < s1.size(); ++i)
            Union(s1[i]-'a', s2[i]-'a');
        
        string res = "";
        for(auto i = 0; i < baseStr.size(); ++i)
            res += find(baseStr[i]-'a') + 'a';
        
        return res;
    }
};