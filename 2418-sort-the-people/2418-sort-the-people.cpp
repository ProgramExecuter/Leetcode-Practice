class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        vector<pair<int, string>> heightAndNames;
        for(int i = 0; i < names.size(); ++i)
            heightAndNames.push_back({heights[i], names[i]});
        
        sort(heightAndNames.begin(), heightAndNames.end(), greater<pair<int,string>>());
        
        vector<string> res;
        for(auto curr : heightAndNames)
            res.push_back(curr.second);
        
        return res;
    }
};