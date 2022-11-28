class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> allPlayers;
        map<int, int> playerLossCnt;
        
        for(auto match : matches) {
            allPlayers.insert(match[0]);
            allPlayers.insert(match[1]);
            
            playerLossCnt[match[1]] += 1;
        }
        
        vector<int> noLossPlayers, oneLossPlayers;
        for(auto player : allPlayers) {
            if(playerLossCnt.find(player) == playerLossCnt.end()) {
                noLossPlayers.push_back(player);
            }
            else if(playerLossCnt[player] == 1) {
                oneLossPlayers.push_back(player);
            }
        }
        
        return {noLossPlayers, oneLossPlayers};
    }
};