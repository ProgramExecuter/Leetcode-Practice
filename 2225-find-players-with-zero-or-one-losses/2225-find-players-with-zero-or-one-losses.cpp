class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // Track all the players
        set<int> allPlayers;
        
        // Track the loss count of each player
        map<int, int> playerLossCnt;
        
        // Check for each match
        for(auto match : matches) {
            // Store each player
            allPlayers.insert(match[0]);
            allPlayers.insert(match[1]);
            
            // Track the cnt of loss
            playerLossCnt[match[1]] += 1;
        }
        
        vector<int> noLossPlayers, oneLossPlayers;
        
        // Check for all players (in ascending order)
        for(auto player : allPlayers) {
            // This player never lost
            if(playerLossCnt.find(player) == playerLossCnt.end())
                noLossPlayers.push_back(player);
            // This player lost exactly once
            else if(playerLossCnt[player] == 1)
                oneLossPlayers.push_back(player);
        }
        
        return {noLossPlayers, oneLossPlayers};
    }
};