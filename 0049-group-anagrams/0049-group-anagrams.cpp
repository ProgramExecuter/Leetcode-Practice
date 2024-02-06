class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string, vector<string>> mpRes;
        for(string str : strs)
        {
            string tmp = str;
            sort(str.begin(), str.end());
            
            mpRes[str].push_back(tmp);
        }
        
        vector<vector<string>> res;
        
        for(auto i : mpRes)
        {
            res.push_back(i.second);
        }
        
        return res;
    }
};