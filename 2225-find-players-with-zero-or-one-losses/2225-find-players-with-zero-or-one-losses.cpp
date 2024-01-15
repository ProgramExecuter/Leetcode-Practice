struct playerStats {
    int wonCnt;
    int loseCnt;
};
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        map<int, playerStats> winLoss;
        
        for(auto match : matches)
        {
            int winner = match[0];
            int loser  = match[1];
            
            winLoss[winner].wonCnt += 1;
            winLoss[loser].loseCnt += 1;
        }
        
        vector<int> noLoss;
        vector<int> oneLoss;
        
        for(auto curr : winLoss)
        {
            // No Loss
            if(curr.second.loseCnt == 0)
                noLoss.push_back(curr.first);
            
            // Only one loss
            if(curr.second.loseCnt == 1)
                oneLoss.push_back(curr.first);
        }
        
        return {noLoss, oneLoss};
    }
};