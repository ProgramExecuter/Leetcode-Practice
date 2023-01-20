class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int, set<int>> userTime;
        map<int, int> timeCnt;
        
        for(auto log : logs) {
            userTime[log[0]].insert(log[1]);
        }
        
        for(auto x : userTime) {
            ++timeCnt[x.second.size()];
        }
        
        vector<int> res(k, 0);
        
        for(auto x : timeCnt)
            res[x.first-1] = x.second;
        
        return res;
    }
};