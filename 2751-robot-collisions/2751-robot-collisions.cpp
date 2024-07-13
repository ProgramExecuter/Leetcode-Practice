class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) 
    {
        int len = positions.size();
        vector<vector<int>> robots;
        
        for(int i = 0; i < len; ++i)
            robots.push_back({positions[i], healths[i], directions[i], i});
        // [0] position     [1] healths     [2] directions
        
        sort(robots.begin(), robots.end());        
        
        stack<pair<int, int>> healthIdxStack;
        
        for(int i = 0; i < len; ++i)
        {
            int currRoboPos = robots[i][0];
            int currRoboHealth = robots[i][1];
            int currRoboDir = robots[i][2];
            int currRoboIdx = robots[i][3];
            
            if(currRoboDir == 'R')
                healthIdxStack.push({currRoboHealth, currRoboIdx});
            else
            {
                int currTmpHealth = currRoboHealth;
                while(!healthIdxStack.empty())
                {
                    int tmpOutHealth = healthIdxStack.top().first, tmpOutIdx = healthIdxStack.top().second;
                    healthIdxStack.pop();
                    
                    if(tmpOutHealth > currTmpHealth)
                    {
                        healthIdxStack.push({tmpOutHealth-1, tmpOutIdx});
                        healths[currRoboIdx] = 0;
                        currTmpHealth = 0;
                        break;
                    }
                    else if(tmpOutHealth < currTmpHealth)
                    {
                        healths[tmpOutIdx] = 0;
                        --currTmpHealth;
                    }
                    else
                    {
                        healths[tmpOutIdx] = healths[currRoboIdx] = 0;
                        currTmpHealth = 0;
                        break;
                    }
                }
                
                // Robot with remaining health after iterating stack
                if(currTmpHealth > 0)
                    healths[currRoboIdx] = currTmpHealth;
            }
        }
        
        // Update health of robots remaining in stack
        while(!healthIdxStack.empty())
        {
            healths[healthIdxStack.top().second] = healthIdxStack.top().first;
            healthIdxStack.pop();
        }
        
        // Add all robots with health remaining
        vector<int> res;
        for(int i = 0; i < len; ++i)
        {
            if(healths[i] > 0)
                res.push_back(healths[i]);
        }
        
        return res;
    }
};







