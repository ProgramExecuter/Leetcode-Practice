class Solution {
public:
    void util(vector<int>& vals, vector<vector<int>>& edges, map<int, vector<int>> &mp) {
        for(auto i : edges) {
            mp[i[0]].push_back(vals[i[1]]);
            mp[i[1]].push_back(vals[i[0]]);
        }
    }
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        map<int, vector<int>> mp;
        
        util(vals, edges, mp);
        
        int ans = INT_MIN;
            
        for(int idx = 0; idx < n; ++idx) {
            int tmpSum = vals[idx];
            ans = max(ans, tmpSum);
            
            sort(mp[idx].begin(), mp[idx].end(), greater<int>());
            
            for(int i = 0 ; i < min(int(mp[idx].size()), k); ++i) {
                tmpSum += mp[idx][i];
                ans = max(ans, tmpSum);
            }
        }
        
        return ans;
    }
};