class Solution {
public:
    int f(int idx, int prevIdx, vector<pair<int, int>> &ageScore, vector<vector<int>> &dp) {
        if(idx == ageScore.size())        return 0;
        
        if(dp[idx][prevIdx] != -1)
            return dp[idx][prevIdx];
        
        int pick = 0, notPick = 0;
        
        // Pick
        bool ageGreatPrev = ageScore[idx].first > ageScore[prevIdx].first;
        bool scoreLessPrev = ageScore[idx].second < ageScore[prevIdx].second;
        
        if(!(ageGreatPrev  and  scoreLessPrev))
            pick = ageScore[idx].second + f(idx+1, idx, ageScore, dp);
        
        // Not Pick
        notPick = f(idx+1, prevIdx, ageScore, dp);
        
        return dp[idx][prevIdx] = max(pick, notPick);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        
        // Create a vector of pair<age, score>, and sort it
        vector<pair<int, int>> ageScore;
        ageScore.push_back({0, 0});
        for(int i = 0; i < n; ++i)
            ageScore.push_back({ages[i], scores[i]});
        sort(ageScore.begin(), ageScore.end());
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        for(auto i : ageScore)
            cout << i.first << " " << i.second << endl;
        cout << endl;
        
        return f(1, 0, ageScore, dp);
    }
};