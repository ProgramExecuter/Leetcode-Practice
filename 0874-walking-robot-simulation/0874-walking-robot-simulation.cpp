class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int currX = 0, currY = 0;
        char currDir = 'N';
        int maxDist = 0;
        
        set<pair<int,int>> st;
        for(auto i : obstacles)     st.insert({i[0],i[1]});
        
        for(int cmd : commands)
        {
            if(cmd == -1)
            {
                if(currDir == 'N')          currDir = 'E';
                else if(currDir == 'E')     currDir = 'S';
                else if(currDir == 'S')     currDir = 'W';
                else                        currDir = 'N';
            }
            else if(cmd == -2)
            {
                if(currDir == 'N')          currDir = 'W';
                else if(currDir == 'E')     currDir = 'N';
                else if(currDir == 'S')     currDir = 'E';
                else                        currDir = 'S';
            }
            else
            {
                int delX = 0, delY = 0;
                if(currDir == 'N')          delY = 1;
                else if(currDir == 'E')     delX = 1;
                else if(currDir == 'S')     delY = -1;
                else                        delX = -1;
                
                while(cmd--)
                {
                    if(st.find({currX+delX, currY+delY}) != st.end())
                        break;
                    currX += delX;
                    currY += delY;
                }
            }
            maxDist = max(maxDist, currX*currX + currY*currY);
        }
        
        return maxDist;
    }
};