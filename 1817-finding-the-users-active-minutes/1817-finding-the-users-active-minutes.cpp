class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        // Track each user's activity time on their respectve 'set'
        map<int, set<int>> userTime;
        for(auto log : logs)
            userTime[log[0]].insert(log[1]);
        
        vector<int> res(k, 0);
        
        // Count the no. of users who have activity time in range [0, k]
        // and save them in respective time grid
        for(auto i : userTime)
            ++res[i.second.size()-1];
        
        return res;
    }
};