class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
        vector<vector<int>> mp(26, vector<int>());
        
        for(int i = 0; i < s.size(); ++i)
            mp[s[i]-'a'].push_back(i);
        
        int res = -1;
        for(auto arr : mp)
        {
            if(arr.size() < 2)  continue;
            
            int first = arr[0], last = arr[arr.size()-1];
            
            res = max(res, last-first-1);
        }
        
        return res;
    }
};